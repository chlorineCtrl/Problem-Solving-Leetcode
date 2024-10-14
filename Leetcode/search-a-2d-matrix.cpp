
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowTop = 0;
        int rowBottom = matrix.size()-1;

        while(rowTop < rowBottom){
            int mid = rowTop + (rowBottom - rowTop) / 2;

            if(matrix[mid][0] == target){
                return true;
            }
            if(matrix[mid][0] < target && matrix[mid+1][0] > target){
                rowTop = mid;
                break;
            }
            if(matrix[mid][0] < target){
                rowTop = mid +1;

            } else rowBottom = mid -1;
        }

        int theRow = rowTop;
        int colLeft = 0;
        int colRight = matrix[theRow].size() -1;

        while(colLeft <= colRight){
            int mid = colLeft + (colRight - colLeft) /2;

            if(matrix[theRow][mid] == target){
                return true;
            }

            if(matrix[theRow][mid] < target){
                colLeft = mid+1;
            }else colRight = mid -1;
        }
        return false;
    }
};
