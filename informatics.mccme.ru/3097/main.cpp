#include<fstream>
#include<vector>

class PascalArray {
    
    private:

        int left;
        int* storage;
        int length;

        int getIndex(int i) {
            return i - left;
        }

    public:

        PascalArray(int left, int right) {
            
            this->left = left;
            this->length = right - left + 1;

            storage = new int[length];

        }

        int& operator[] (int i) {
            return storage[getIndex(i)];
        }

        int size() {
            return length;
        }

        void fill(int n) {
            
            for (int i = left; i < left + length; i++) {
                storage[getIndex(i)] = n;
            }

        }

};

const int N_MAX = 100;
const int M_MAX = 100;
const char NO_ANSWER[] = "Impossible";
const int INFINITY = 100000;

int s;
int n;
int p[N_MAX];
int m;
int q[M_MAX];

std::vector<int> answers;

void in() {
    
    scanf("%d", &s);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", q + i);
    }

}

void solution() {
   
    int elementsLength = n + m;
    int* elements = new int[elementsLength];

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        elements[i] = p[i];
        right += p[i];
    }

    for (int i = 0; i < m; i++) {
        elements[n + i] = -q[i];
        left -= q[i]; 
    }

    if (s > right) {
        return;
    }

    std::vector<PascalArray> knapsack;

    for (int i = 0; i < elementsLength; i++) {

        knapsack.push_back(PascalArray(left, right));

        knapsack[i].fill(-INFINITY);
        knapsack[i][0] = 0;

    }

    knapsack[0][elements[0]] = 0;

    for(int i = 1; i < elementsLength; i++) {

        for(int j = left; j <= right; j++) {
            
            if (knapsack[i - 1][j] != -INFINITY) {

                knapsack[i][j] = knapsack[i - 1][j];
                knapsack[i][j + elements[i]] = j;

            }

        }

    }

    if (knapsack[elementsLength - 1][s] != -INFINITY) {

        int sum = s;
        int level = elementsLength - 1;

        while(sum != 0) {

            if (level > 0 && knapsack[level][sum] == knapsack[level - 1][sum]) {
                level--;
                continue;
            }

            answers.push_back(elements[level]);
            sum = knapsack[level--][sum];

        }

    }

}

void out() {
    
    if (answers.empty()) {
        printf("%s\n", NO_ANSWER);
    }

    for (int i = 0; i < answers.size(); i++) {

        printf(
            "%s%d%s",
            answers[i] < 0 ? "" : "+",
            answers[i],
            i + 1 != answers.size() ? " " : "\n"
        );
    
    }

}

int main() {
    in();
    solution();
    out();
    return 0;
}
