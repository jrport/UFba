#include <iostream>
#include <vector>

std::vector<int> parte;

std::vector<int> series(int i){
	if(i==1){
		parte.push_back(1);
	}
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
	return parte;
}

int main(){
	int n;
	std::vector<int> sequence;
	std::cin>>n;
	// std::vector<int> parter;
	sequence = series(n);
	for (int i:sequence){
		printf("%d ",i);
	}
	std::cout<<"\n";
	return 0;
}
