#include<stdio.h>
#include<vector>

const int N_MIN = 0, N_MAX = 14;
const int M_MIN = 1, M_MAX = 100;
const int GROUPS = 4;
const char NO_ANSWER[] = "No solution";

int n;
int m[N_MAX];

int sum[1 << N_MAX];
std::vector<int> graph[1 << N_MAX];

std::vector<int> answers; 

void in() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

}

bool dfs(std::vector<int>& group, int current_number, int current_sum) {

    if (group.size() == GROUPS) {
        
        if (current_number == (1 << n) - 1) {
            return true;
        }

        return false;

    }

    int from = group[ group.size() - 1 ];

    for (int i = 0; i < graph[from].size(); i++) {

        int next = graph[from][i];

        if ( (current_number & next) == 0 && current_sum == sum[next] ) {

            group.push_back(next);
            bool res = dfs(group, current_number | next, sum[next]);

            if (res) {
                return res;
            }

            group.pop_back();

        }

    }

    return false;

}

void solution() {

    int k = 1 << n;
    for (int i = 1; i < k; i++) {
    
        for (int j = 0; j < n; j++) {
            
            if (i & (1 << j)) {
                sum[i] += m[j];
            }

        }

    }

    for (int i = 1; i < k; i++) {
    
        for(int j = i + 1; j < k; j++) {
            
            if ( (i & j) == 0 && sum[i] == sum[j] ) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }

        }

    }

    for (int i = 1; i < k; i++) {
        
        answers.push_back(i);
        dfs(answers, i, sum[i]);

        if (answers.size() == GROUPS) {
            break;
        }

        answers.pop_back();

    }

}

void out() {

    if (answers.empty()) {

        printf("%s\n", NO_ANSWER);    
    
    } else {

        for (int i = 0; i < answers.size(); i++) {

            int k = 0;
            for (int j = 0; j < n; j++) {
                
                if (answers[i] & (1 << j)) {
                    printf("%s%d", k++ > 0 ? " " : "", j + 1);
                }

            }

            printf("\n");

        }

    }

}

int main() {
    in();
    solution();
    out();
    return 0;
}


