#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Please provide the input file\n";
        return 1;
    }

    ifstream in(argv[1]);
    if (!in) {
        cout << "Could not open input file.\n";
        return 1;
    }

    int P, R;
    in >> P >> R;

    vector<vector<int> > alloc(P, vector<int>(R));
    vector<vector<int> > mx(P, vector<int>(R));
    vector<vector<int> > need(P, vector<int>(R));
    vector<int> avail(R);

    // Allocation matrix
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            in >> alloc[i][j];

    // Max matrix
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            in >> mx[i][j];

    // Available vector
    for (int j = 0; j < R; j++)
        in >> avail[j];

    // Calculate Need matrix
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = mx[i][j] - alloc[i][j];

    // process details
    cout << "Process:\n";
    cout << "-----------\n";
    for (int i = 0; i < P; i++) {
        cout << "P" << i << ": Max = [";
        for (int j = 0; j < R; j++) {
            cout << mx[i][j];
            if (j < R - 1) cout << "  ";
        }
        cout << "], Allocation = [";
        for (int j = 0; j < R; j++) {
            cout << alloc[i][j];
            if (j < R - 1) cout << "  ";
        }
        cout << "], Need = [";
        for (int j = 0; j < R; j++) {
            cout << need[i][j];
            if (j < R - 1) cout << "  ";
        }
        cout << "]\n";
    }

    cout << "\nAvailable Resources = [";
    for (int j = 0; j < R; j++) {
        cout << avail[j];
        if (j < R - 1) cout << "  ";
    }
    cout << "]\n\n";

    // Safety
    vector<int> work = avail;
    vector<bool> finish(P, false);
    vector<int> safeSeq;

    for (int count = 0; count < P; count++) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                // Show process
                cout << "Process P" << i << " with Need = [";
                for (int j = 0; j < R; j++) cout << need[i][j] << " ";
                cout << "] and Work = [";
                for (int j = 0; j < R; j++) cout << work[j] << " ";
                cout << "]\n";

                bool canRun = true;
                for (int j = 0; j < R; j++)
                    if (need[i][j] > work[j]) canRun = false;

                if (canRun) {
                    cout << "Process P" << i << " can run. \n\n";
                    for (int j = 0; j < R; j++)
                        work[j] += alloc[i][j];
                    finish[i] = true;
                    safeSeq.push_back(i);
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    bool safe = true;
    for (int i = 0; i < P; i++)
        if (!finish[i]) safe = false;

    if (safe) {
        cout << "System is in a SAFE state.\n";
        cout << "Safe sequence: ";
        for (int i = 0; i < P; i++) {
            cout << "P" << safeSeq[i];
            if (i < P - 1) cout << " -> ";
        }
        cout << "\n";
    } else {
        cout << "System is NOT in a safe state.\n";
    }

    return 0;
}
