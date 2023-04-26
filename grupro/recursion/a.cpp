#include <iostream>
#include <vector>

int series(int i){
	std::vector<int> parte;
	if (i==2){
		//std::vector<int> parte;
		parte.push_back(1);
		parte.push_back(2);
		parte.push_back(1);
	}
	else if (i>2){
		//std::vector<int> parte;
		series(i-1);
 		parte.push_back(i);
 		series(i-1);
	}	
	for(int a:parte){
		std::cout<<a;
	} 
	return 0;
}

int main(){
	int n;
	std::cin>>n;
	series(n);
	std::cout<<"\n";
	return 0;
}