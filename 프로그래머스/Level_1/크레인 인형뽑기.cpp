#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int iMaxRow = board[1].size();
    int iCurCol = 0;               // 현재 크레인 moves가 뽑으려는 열 위치

    vector<int> bin = {0};         // 뽑은 인형을 담을 컨테이너

    int loopCount = moves.size();
    int score = 0;
    int scorecalculate = 2;        // 점수 계산 공식

    int prevItem = 0;              // 이전에 뽑은 인형 정보
    int curItem = 0;               // 현재 뽑은 인형 정보

    // loopCount 만큼 Game 횟수 설정
    for (int i = 0; i < loopCount; ++i)
    {
        iCurCol = moves[i] - 1;

        for (int k = 0; k < bin.size(); ++k)
        {
            // 뽑기 전 바구니에 마지막에 담긴 인형의 정보를 확인
            if (k + 1 == bin.size())
            {
                prevItem = bin[k];
                break;
            }
            else if (bin[k] == 0 && k != 0)
            {
                prevItem = bin[k - 1];
                break;
            }
        }        
        
        // 각 행에서 뽑을 열의 정보를 확인
        for (int j = 0; j < iMaxRow; ++j)
        {
            // 해당 열에 Item이 존재하는 경우
            if (board[j][iCurCol] != 0)
            {
                curItem = board[j][iCurCol];
                bin.push_back(curItem);                
                board[j][iCurCol] = 0;

                // 이전 Item 과 현재 뽑은 Item의 정보가 일치하는 경우
                if (prevItem != 0 && prevItem == curItem)
                {
                    bin.pop_back();
                    bin.pop_back();
                    ++score;
                }

                break;
            }
        }
    }

    return score * scorecalculate;
}