#include <iostream>
int divided(int, int, int&, int&); // 함수 선언. 입력 2, 출력을위한 참조자 입력2
int absm(int); // 추가 인클루드없이 숫자 테스트를 위한 abs()함수 구현
int main(){
	//입력2 출력2
	int val1,val2; // 입력받을 변수
	int div,mod;	// 출력할 변수 (div = 몫, mod=나머지)
//	val1=val2=0;

	std::cout<<"나눗셈을 합니다"<<"\n"<<"숫자 2개를 입력해주세요. 구별은 엔터로 실시합니다.\n"<<std::endl;
	std::cout<<"[연산 형태:: (숫자1) / (숫자2) = 결과]\n"<<std::endl;
	//안내 및 구현형태 알림


	try{
		std::cin>>val1; // 나눌 숫자 1을 받아옵니다
		std::cin>>val2; // 나눌 숫자 2를 받아옵니다
		std::cout<<"입력된 값::"<<val1<<", "<<val2<<std::endl;
		divided(val1, val2, div, mod); // 함수 실행
	//	break;
	//
		std::cout<<"결과:: "<<std::endl;
		std::cout<<"\n 몫::"<<div<<"\n 나머지::"<<mod<<std::endl;
	}
	catch(char worng_input){
		std::cout<<"잘못된 문자 ["<<worng_input<<" ] 가 입력되었습니다"<<std::endl; // 오류문자 리턴
	}
	catch(int expn){ // 틀린 숫자 관련
		if(expn==0){
			std::cout<<"0으로 나눌 수 없습니다"<<std::endl;} //0으로 나눌때의 오류
	else{
		std::cout<<"비 정상적인 숫자가 입력되었습니다"<<std::endl;}
	//그 외 숫자관련 오류 리턴
	std::cout<<"다시진행하시려면 재 시작해주십시오"<<std::endl;
	}
}

int divided(int num1, int num2, int &ref1, int &ref2){
	 if (!(absm(num1)>0)) 	// 입력받은 문자가 옳은지 점검
		throw num1;	// 숫자의 절대값이 0보다 크지않다면
	else if (!(absm(num2)>0))//이는 '0'으로 인식하여 연산을 중지하고 
		throw num2;	//예외로 리턴함.
				//0인지 아닌지만 검사하기 때문에
				//음수값으로 나눌 수도 있음.
	ref1=num1/num2;		//나눈 몫을 참조자로 리턴
	ref2=num1%num2;		//나눈 나머지를 참조자로 리턴
}

int absm(int base){		//math의 abs함수 구현
	if (base>=0)		//입력값이 0보다 클경우 (0포함)
	return base;		//그대로 리턴
	else if (base<0)	//0보다 작을경우(음수일시)
	return -base;		//양수로 리턴
}
