#include <string.h>

int hamming(char str1[], char str2[]){
	int i = 0, distance = 0;
	for(i; i < length(str1); i++){
		if(str1[i] != str2[i])
			distance++;
	}
	return distance;
}

int length(char ar[]){
	return sizeof(ar)/sizeof(char);
}

int levenshtein(char str1[], int i, int length1, char str2[], int j, int length2){
	
	if(length1 == 0) 
		return length2;
	if(length2 == 0)
		return length1;
		
	int cost = 0;
	if(str1[i] != str2[j])
		cost = 1;
	int f = levenshtein(str1, i+1, length1-1, str2, j, length2) + 1;
	int s = levenshtein(str1, i, length1, str2, j+1, length2-1) + 1;
	int t = levenshtein(str1, i+1, length1 -1, str2, j+1, length2-1) + cost;
	
	return minimum(f,s,t); 
	
}

int minimum(int f, int s, int t){
	if(f <= s && f <= t)
		return f;
	if(s <= f && s <= t)
		return s;
	if(t <= f && t <= s)
		return t;	
}

int main(){
	char str[24];
	char str2[24];
	
	strcpy(str, "ls");
	strcpy(str2, "lr");
	//int h = levenshtein(str, 0, str2, 0);
	int h = levenshtein(str, 0, length(str), str2, 0, length(str2));
	printf("distance between %s and %s is: %d\n", str, str2, h);
	return 0;
}
