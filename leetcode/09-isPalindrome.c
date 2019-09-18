
/**

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

*/

int getCount(int x) {
    int count = 0;
    while (x != 0) {
        count++;
        x /= 10;
    }
    
    return count;
}

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    
    if (x < 10) {
        return true;
    }
    
    int number = getCount(x);
    char *content = malloc(number+1);
    sprintf(content, "%d", x);
    
    int reachIndex = number / 2 - 1;
    int leftIndex = 0;
    int rightIndex = number - 1;

    bool result = true;
    while (leftIndex <= reachIndex) {
        if (content[leftIndex] != content[rightIndex]) {
            result = false;
            break;
        }

        leftIndex++;
        rightIndex--;
    }
    free(content);
    
    return result;
}

