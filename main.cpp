#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPSILON = 1E-9;

int RankDariMatriks(vector<vector<double>>& matriks) {
    int n = matriks.size();
    int m = matriks[0].size();

    int rank = 0;
    vector<bool> baris_dipilih(n, false);
    for (int i = 0; i < m; ++i) {
        int j;
        for (j = 0; j < n; ++j) {
            if (!baris_dipilih[j] && std::abs(matriks[j][i]) > EPSILON)
                break;
        }

        if (j != n) {
            ++rank;
            baris_dipilih[j] = true;
            for (int p = i + 1; p < m; ++p)
                matriks[j][p] /= matriks[j][i];
            for (int k = 0; k < n; ++k) {
                if (k != j && std::abs(matriks[k][i]) > EPSILON) {
                    for (int p = i + 1; p < m; ++p)
                        matriks[k][p] -= matriks[j][p] * matriks[k][i];
                }
            }
        }
    }
    return rank;
}

int main() {
    int n, m;
    cout << "Masukkan jumlah baris: ";
    cin >> n;
    cout << "Masukkan jumlah kolom: ";
    cin >> m;

    vector<vector<double>> matriks(n, vector<double>(m));
    cout << "Masukkan elemen-elemen dari matriks:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matriks[i][j];
        }
    }

    int rank = RankDariMatriks(matriks);

    cout << "Matriks setelah diproses:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matriks[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Rank dari matriks adalah: " << rank << endl;

    return 0;
}
