#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#define ID_NUMS_COUNT 9 
#define ACC_NUMS_COUNT 16

class BankAccount {
    private:
        char* name;
        char* surname;
        char* passId;
        float balanceAMD;
        float balanceEUR;
        float balanceUSD;
        float balanceRUB;
        static float totalBalanceAMD;
        static float totalBalanceEUR;
        static float totalBalanceUSD;
        static float totalBalanceRUB;
        int accountNum[ACC_NUMS_COUNT];
        static unsigned int accountCount;

		//Check validations
		bool isValidPassId(const char* passId);
		bool isValidAccountNum(int accountNum[ACC_NUMS_COUNT]);
		bool isValidSurName(const char* SurName);
		bool isValidBalance(float balance);

    public:

		//Constructors
		BankAccount();
	    BankAccount(const char* name, const char* surname, const char* passId, int accountNumParam[ACC_NUMS_COUNT], float balanceAMD = 0.0, float balanceEUR = 0.0, float balanceUSD = 0.0, float balanceRUB = 0.0);
		
		// Destructor
		~BankAccount();

		//Get functions
		const char* getName();
		const char* getSurname();
		const char* getPassId();
		float getBalanceAMD();
		float getBalanceEUR();
		float getBalanceUSD();
		float getBalanceRUB();
		void getBalance();
		static float getTotalBalanceAMD();
		static float getTotalBalanceEUR();
		static float getTotalBalanceUSD();
		static float getTotalBalanceRUB();
		static void getTotalBalance();
		void getAllInfo();
		int* getAccountNum();		
		static unsigned int getAccountCount();

		//Set functions
		bool setPassId(const char* passId);
		bool setBalanceAMD(float balance);
		bool setBalanceEUR(float balance);
		bool setBalanceUSD(float balance);
		bool setBalanceRUB(float balance);
			
};

#endif