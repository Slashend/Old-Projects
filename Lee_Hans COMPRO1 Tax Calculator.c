#include <stdio.h>
#include <conio.h>

/*
Name: greet
Purpose: display user greeting and instructions (that the user may be looped back to correct invalid information)
Pre-conditions: user must have been able to execute the program
Post-conditions: user will know about the possible looping within the program
Return value: none
Parameters: none
*/
void greet(){
        printf("Hello!  This program is a Withholding Tax Calculator which computes for your \nwithholding tax based on monthly income.\n" );
        printf("\nPlease keep in mind that if you enter any invalid information, you may be \ntaken back to repeat a step for you to re-enter said information.\n");
        printf("\nTo get you started, please enter the following information:\n\n");
}  
               
/*
Name: dependentcheck
Purpose: check whether the candidate(s) for dependency are legitimate dependents
Pre-conditions:  know the validated number of dependent candidates as well as each candidate's 
                 employment status, marital status and age
Post-conditions: have an integer value with the number of qualified dependents, greater than or equal to zero 
                 yet not exceeding four 
Return value: an integer value for the number of actual dependents (from 0 to 4)
Parameters: (into: int numdependent) , (out and back to the calling function: int dependents)
*/  
int dependentcheck(int numdependent){
        int 
        age/*candidate's age*/,
        work/*candidate's employment or unemployment*/,
        status/*candidate's civil status*/,
        dependents/*number of validated dependents*/,
        i/*increment counter*/;
    
        dependents=0;
        for(i=1; i<=numdependent; i++){
                printf("\nEnter candidate info:\n");
                do{
                        printf("Is this candidate employed? (1 for employed , 0 for not.) ");
                        scanf("%d",&work);
                  }
                while(!((work==0)||(work==1)));
    
        do{
                printf("Is this candidate married? (1 for married , 0 for not.) ");
                scanf("%d",&status);
          }
          while(!((status==0)||(status==1)));
    
        do{
                printf("How old is this candidate? (In years) ");
                scanf("%d",&age);
          }
          while(age<0);
    
        if((work==0)&&(status==0)&&(age<21))
                dependents+=1;
        else
                dependents=dependents;
    }
        return dependents;
}

/*
Name: SSScompEE
Purpose: to compute and return the user's SSS contribution given his Gross Income provided that he is an employee
Pre-conditions: know the user's gross income in Philippine Pesos and confirm that the tax is to be computed as an employee
Post-conditions: have the user's SSS contribution in Philippine Pesos
Return value: an double value which is the user's SSS contribution in Philippine Pesos
Parameters: (into: double grossincome) , (out and back to the calling function: double SSS)
*/       
double SSScompEE(double grossincome){
        if(grossincome<1000)
                return 0.00;
        else if(grossincome>=1000&&grossincome<1250)
                return 36.30;
        else if(grossincome>=1250&&grossincome<1750)
                return 54.50;
        else if(grossincome>=1750&&grossincome<2250)
                return 72.70;
        else if(grossincome>=2250&&grossincome<2750)
                return 90.80;
        else if(grossincome>=2750&&grossincome<3250)
                return 109.00;
        else if(grossincome>=3250&&grossincome<3750)
                return 127.20;
        else if(grossincome>=3750&&grossincome<4250)
                return 145.30;
        else if(grossincome>=4250&&grossincome<4750)
                return 163.50;
        else if(grossincome>=4750&&grossincome<5250)
                return 181.70;
        else if(grossincome>=5250&&grossincome<5750)
                return 199.80;
        else if(grossincome>=5750&&grossincome<6250)
                return 218.00;
        else if(grossincome>=6250&&grossincome<6750)
                return 236.20;
        else if(grossincome>=6750&&grossincome<7250)
                return 254.30;
        else if(grossincome>=7250&&grossincome<7750)
                return 272.50;
        else if(grossincome>=7750&&grossincome<8250)
                return 290.70;
        else if(grossincome>=8250&&grossincome<8750)
                return 308.80;
        else if(grossincome>=8750&&grossincome<9250)
                return 327.00;
        else if(grossincome>=9250&&grossincome<9750)
                return 345.20;
        else if(grossincome>=9750&&grossincome<10250)
                return 363.30;
        else if(grossincome>=10250&&grossincome<10750)
                return 381.50;
        else if(grossincome>=10750&&grossincome<11250)
                return 399.70;
        else if(grossincome>=11250&&grossincome<11750)
                return 417.80;
        else if(grossincome>=11750&&grossincome<12250)
                return 436.00;
        else if(grossincome>=12250&&grossincome<12750)
                return 454.20;
        else if(grossincome>=12750&&grossincome<13250)
                return 472.30;
        else if(grossincome>=13250&&grossincome<13750)
                return 490.50;
        else if(grossincome>=13750&&grossincome<14250)
                return 508.70;
        else if(grossincome>=14250&&grossincome<14750)
                return 526.80;
        else if(grossincome>=14750&&grossincome<15250)
                return 545.00;
        else if(grossincome>=15250&&grossincome<15750)
                return 563.20;
        else if(grossincome>=15750)
                return 581.30; 
        else
                return 0; 
}

/*
Name: SSScompER
Purpose: to compute and return the user's SSS contribution given his Gross Income provided that he is an employer
Pre-conditions: know the user's gross income in Philippine Pesos and confirm that the tax is to be computed as an employer
Post-conditions: have the user's SSS contribution in Philippine Pesos
Return value: an double value which is the user's SSS contribution in Philippine Pesos
Parameters: (into: double grossincome) , (out and back to the calling function: double SSS)
*/       
double SSScompER(double grossincome){
        if(grossincome<1000)
                return 0.00;
        else if(grossincome>=1000&&grossincome<1250)
                return 73.70;
        else if(grossincome>=1250&&grossincome<1750)
                return 110.50;
        else if(grossincome>=1750&&grossincome<2250)
                return 147.30;
        else if(grossincome>=2250&&grossincome<2750)
                return 184.20;
        else if(grossincome>=2750&&grossincome<3250)
                return 221.00;
        else if(grossincome>=3250&&grossincome<3750)
                return 257.80;
        else if(grossincome>=3750&&grossincome<4250)
                return 294.70;
        else if(grossincome>=4250&&grossincome<4750)
                return 331.50;
        else if(grossincome>=4750&&grossincome<5250)
                return 368.30;
        else if(grossincome>=5250&&grossincome<5750)
                return 405.20;
        else if(grossincome>=5750&&grossincome<6250)
                return 442.00;
        else if(grossincome>=6250&&grossincome<6750)
                return 478.80;
        else if(grossincome>=6750&&grossincome<7250)
                return 515.70;
        else if(grossincome>=7250&&grossincome<7750)
                return 552.50;
        else if(grossincome>=7750&&grossincome<8250)
                return 589.30;
        else if(grossincome>=8250&&grossincome<8750)
                return 626.20;
        else if(grossincome>=8750&&grossincome<9250)
                return 663.00;
        else if(grossincome>=9250&&grossincome<9750)
                return 699.80;
        else if(grossincome>=9750&&grossincome<10250)
                return 736.70;
        else if(grossincome>=10250&&grossincome<10750)
                return 773.50;
        else if(grossincome>=10750&&grossincome<11250)
                return 810.30;
        else if(grossincome>=11250&&grossincome<11750)
                return 847.20;
        else if(grossincome>=11750&&grossincome<12250)
                return 884.00;
        else if(grossincome>=12250&&grossincome<12750)
                return 920.80;
        else if(grossincome>=12750&&grossincome<13250)
                return 957.70;
        else if(grossincome>=13250&&grossincome<13750)
                return 994.50;
        else if(grossincome>=13750&&grossincome<14250)
                return 1031.30;
        else if(grossincome>=14250&&grossincome<14750)
                return 1068.20;
        else if(grossincome>=14750&&grossincome<15250)
                return 1105.00;
        else if(grossincome>=15250&&grossincome<15750)
                return 1141.80;
        else if(grossincome>=15750)
                return 1178.70;
        else
                return 0; 
}

/*
Name: SSScompOFW
Purpose: to compute and return the user's SSS contribution given his Gross Income provided that he is an Overseas Filipino Worker
Pre-conditions: know the user's gross income in Philippine Pesos and and confirm that the tax is to be computed as an Overseas Filipino Worker
Post-conditions: have the user's SSS contribution in Philippine Pesos
Return value: an double value which is the user's SSS contribution in Philippine Pesos
Parameters: (into: double grossincome) , (out and back to the calling function: double SSS)
*/        
double SSScompOFW(double grossincome){
        
        if(grossincome<4750){
                printf("In computing SSS as an OFW, the minimum gross income to be used is P 4750.00.\n");
                printf("In line with this, your SSS is set at P 0.00\n");
                return 0.00;
        }

        else if(grossincome>=4750&&grossincome<5250)
                return 550.00;
        else if(grossincome>=5250&&grossincome<5750)
                return 605.00;
        else if(grossincome>=5750&&grossincome<6250)
                return 660.00;
        else if(grossincome>=6250&&grossincome<6750)
                return 715.00;
        else if(grossincome>=6750&&grossincome<7250)
                return 770.00;
        else if(grossincome>=7250&&grossincome<7750)
                return 825.00;
        else if(grossincome>=7750&&grossincome<8250)
                return 880.00;
        else if(grossincome>=8250&&grossincome<8750)
                return 935.00;
        else if(grossincome>=8750&&grossincome<9250)
                return 990.00;
        else if(grossincome>=9250&&grossincome<9750)
                return 1045.00;
        else if(grossincome>=9750&&grossincome<10250)
                return 1100.00;
        else if(grossincome>=10250&&grossincome<10750)
                return 1155.00;
        else if(grossincome>=10750&&grossincome<11250)
                return 1210.00;
        else if(grossincome>=11250&&grossincome<11750)
                return 1265.00;
        else if(grossincome>=11750&&grossincome<12250)
                return 1320.00;
        else if(grossincome>=12250&&grossincome<12750)
                return 1375.00;
        else if(grossincome>=12750&&grossincome<13250)
                return 1430.00;
        else if(grossincome>=13250&&grossincome<13750)
                return 1485.00;
        else if(grossincome>=13750&&grossincome<14250)
                return 1540.00;
        else if(grossincome>=14250&&grossincome<14750)
                return 1595.00;
        else if(grossincome>=14750&&grossincome<15250)
                return 1650.00;
        else if(grossincome>=15250&&grossincome<15750)
                return 1705.00;
        else if(grossincome>=15750)
                return 1760.00;
        else 
                return 0; 
}

/*
Name: SSScompSE
Purpose: to compute and return the user's SSS contribution given his Gross Income provided that he is a self-employed worker
Pre-conditions: know the user's gross income in Philippine Pesos and and confirm that the tax is to be computed as a 
                self-employed individual
Post-conditions: have the user's SSS contribution in Philippine Pesos
Return value: an double value which is the user's SSS contribution in Philippine Pesos
Parameters: (into: double grossincome) , (out and back to the calling function: double SSS)
*/       
double SSScompSE(double grossincome){
        if(grossincome<1000)
                return 0.00;
        else if(grossincome>=1000&&grossincome<1250)
                return 110.00;
        else if(grossincome>=1250&&grossincome<1750)
                return 165.00;
        else if(grossincome>=1750&&grossincome<2250)
                return 220.00;
        else if(grossincome>=2250&&grossincome<2750)
                return 275.00;
        else if(grossincome>=2750&&grossincome<3250)
                return 330.00;
        else if(grossincome>=3250&&grossincome<3750)
                return 385.00;
        else if(grossincome>=3750&&grossincome<4250)
                return 440.00;
        else if(grossincome>=4250&&grossincome<4750)
                return 495.00;
        else if(grossincome>=4750&&grossincome<5250)
                return 550.00;
        else if(grossincome>=5250&&grossincome<5750)
                return 605.00;
        else if(grossincome>=5750&&grossincome<6250)
                return 660.00;
        else if(grossincome>=6250&&grossincome<6750)
                return 715.00;
        else if(grossincome>=6750&&grossincome<7250)
                return 770.00;
        else if(grossincome>=7250&&grossincome<7750)
                return 825.00;
        else if(grossincome>=7750&&grossincome<8250)
                return 880.00;
        else if(grossincome>=8250&&grossincome<8750)
                return 935.00;
        else if(grossincome>=8750&&grossincome<9250)
                return 990.00;
        else if(grossincome>=9250&&grossincome<9750)
                return 1045.00;
        else if(grossincome>=9750&&grossincome<10250)
                return 1100.00;
        else if(grossincome>=10250&&grossincome<10750)
                return 1155.00;
        else if(grossincome>=10750&&grossincome<11250)
                return 1210.00;
        else if(grossincome>=11250&&grossincome<11750)
                return 1265.00;
        else if(grossincome>=11750&&grossincome<12250)
                return 1320.00;
        else if(grossincome>=12250&&grossincome<12750)
                return 1375.00;
        else if(grossincome>=12750&&grossincome<13250)
                return 1430.00;
        else if(grossincome>=13250&&grossincome<13750)
                return 1485.00;
        else if(grossincome>=13750&&grossincome<14250)
                return 1540.00;
        else if(grossincome>=14250&&grossincome<14750)
                return 1595.00;
        else if(grossincome>=14750&&grossincome<15250)
                return 1650.00;
        else if(grossincome>=15250&&grossincome<15750)
                return 1705.00;
        else if(grossincome>=15750)
                return 1760.00;
        else
                return 0;
}

/*
Name: pagibigcompER
Purpose: to compute and return the user's Pag-ibig fund contribution given his gross income, in Philippine Pesos, 
         provided that he is an employer
Pre-conditions: know the user's gross income in Philippine Pesos and confirm that the tax is to be computed as an employer
Post-conditions: have the user's Pag-ibig contribution in Philippine Pesos
Return value: an double value which is based on the user's gross income in Philippine Pesos
Parameters: (into: double grossincome) , (out and back to the calling function: double pagibig)
*/       
double pagibigcompER(double grossincome){
        if(grossincome<=1500)
                return grossincome*0.01;
        else if(grossincome>1500&&grossincome<=5000)
                return grossincome*0.02;
        else if(grossincome>5000)
                return 100;
        else 
                return 0;
}

/*
Name: pagibigcomp
Purpose: to compute and return the user's Pag-ibig fund contribution given his gross income,in Philippine Pesos, 
         provided that he is not an employer
Pre-conditions: know the user's gross income in Philippine Pesos and confirm that the tax is not to be computed as an employer
Post-conditions: have the user's Pag-ibig contribution in Philippine Pesos
Return value: an double value which is based on the user's gross income and confirm that the tax is to be computed as an employee
Parameters: (into: double grossincome) , (out and back to the calling function: double pagibig)
*/       
double pagibigcomp(double grossincome){
        if(grossincome<=5000)
                return grossincome*0.02;
        else if(grossincome>5000)
                return 100;
        else 
                return 0;
}

/*
Name: philhealthcomp
Purpose: to compute and return the user's Philhealth contribution given his gross income in Philippine Pesos 
         provided that he is an employee or an employer
Pre-conditions: know the user's gross income in Philippine Pesos and confirm that the tax is to be computed 
                as an employee or an employer
Post-conditions: have the user's Philhealth contribution in Philippine Pesos
Return value: an double value which is based on the user's gross income in Philippine Pesos
Parameters: (into: double grossincome) , (out and back to the calling function: double philhealth)
*/   
double philhealthcomp(double grossincome){
        if(grossincome<9000)
                return 100.00;
        else if(grossincome>=9000&&grossincome<10000)
                return 112.50;
        else if(grossincome>=10000&&grossincome<11000)
                return 125.00;
        else if(grossincome>=11000&&grossincome<12000)
                return 137.50;
        else if(grossincome>=12000&&grossincome<13000)
                return 150.00;
        else if(grossincome>=13000&&grossincome<14000)
                return 162.50;
        else if(grossincome>=14000&&grossincome<15000)
                return 175.00;
        else if(grossincome>=15000&&grossincome<16000)
                return 187.50;
        else if(grossincome>=16000&&grossincome<17000)
                return 200.00;
        else if(grossincome>=17000&&grossincome<18000)
                return 212.50;
        else if(grossincome>=18000&&grossincome<19000)
                return 225.00;
        else if(grossincome>=19000&&grossincome<20000)
                return 237.50;
        else if(grossincome>=20000&&grossincome<21000)
                return 250.00;
        else if(grossincome>=21000&&grossincome<22000)
                return 262.50;
        else if(grossincome>=22000&&grossincome<23000)
                return 275.00;
        else if(grossincome>=23000&&grossincome<24000)
                return 287.50;
        else if(grossincome>=24000&&grossincome<25000)
                return 300.00;
        else if(grossincome>=25000&&grossincome<26000)
                return 312.50;
        else if(grossincome>=26000&&grossincome<27000)
                return 325.00;
        else if(grossincome>=27000&&grossincome<28000)
                return 337.50;
        else if(grossincome>=28000&&grossincome<29000)
                return 350.00;
        else if(grossincome>=29000&&grossincome<30000)
                return 362.50;
        else if(grossincome>=30000&&grossincome<31000)
                return 375.00;
        else if(grossincome>=31000&&grossincome<32000)
                return 387.50;
        else if(grossincome>=32000&&grossincome<33000)
                return 400.00;
        else if(grossincome>=33000&&grossincome<34000)
                return 412.50;
        else if(grossincome>=34000&&grossincome<35000)
                return 425.00;
        else if(grossincome>=35000)
                return 437.50;
        else
                return 0;
}

/*
Name: philhealthcompOFW
Purpose: to compute and return the user's Philhealth contribution given his gross income in Philippine Pesos 
         provided that he is an Overseas Filipino Worker
Pre-conditions: know the user's gross income and confirm that the tax is to be computed as an Overseas Filipino Worker
Post-conditions: have the user's Philhealth contribution in Philippine Pesos
Return value: an double value which is based on the user's gross income in Philippine Pesos
Parameters: (into: none required) , (out and back to the calling function: double philhealth)

I have also used functions for things as simple as defining Php 200 Philhealth contribution for OFW users for easier editing
  in the future if need be (so that this part of the code will be "isolated" from the main function)
*/  
double philhealthcompOFW(){
        return 200.00;
}

/*
Name: philhealthcompSE
Purpose: to compute and return the user's Philhealth contribution given his gross income in Philippine Pesos 
         provided that he is a self-employed individual
Pre-conditions: know the user's gross income and confirm that the tax is to be computed as a self-employed individual
Post-conditions: have the user's Philhealth contribution in Philippine Pesos
Return value: an double value which is based on the user's gross income
Parameters: (into: double grossincome) , (out and back to the calling function: double philhealth)
*/   
double philhealthcompSE(double grossincome){
        if(grossincome>25000)
                return 300.00;
        else
                return 200.00;  
}

/*
Name: methods
Purpose: to tell the user about the 4 methods of calculating his withholding tax, accept an integer value 
         corresponding to the method of computation, and returns this method for further use
Pre-conditions: know which method of computation to use
Post-conditions: have the method which will be used in the computation for withholding tax
Return value: an integer value which is the user's method of computing for his withholding tax
Parameters: (into: none) , (out and back to the calling function: int method)
*/   
int methods(){
        int method/*user's chosen computation method*/;         
        
        printf("\n[0]Current tax table\n");
        printf("[1]With Sen. Recto's reform\n");
        printf("[2]With Sen. Aquino's reform\n");
        printf("[3]With Sen. Angara's reform\n");

        do{
                printf("Which method do you want to use? Enter integers from 0 to 3 please.");
                scanf("%d",&method);
          }
        while(!(method==0||method==1||method==2||method==3));   

        return method;   
}

/*
Name: dependentcount
Purpose: to ask the user for the number of dependent candidates, passes this number to the dependentcheck() 
         function for validation, and returns this validated value to the main program to use
Pre-conditions: know the number of dependent candidates
Post-conditions: have the number of validated dependent candidates
Return value: an integer value which is the user's method of computing for his withholding tax
Parameters: (into: int dependent) ,(into another function: int numdependent) ,
            (out and back to the calling function: int dependents)
*/   
int dependentcount(int dependent){
        int 
        numdependent/*number of dependent candidates*/,
        dependents/*number of validated dependents*/; 
                    
                    if(dependent)
                    {
                            do{
                                    printf("How many dependent candidates are there? Enter integers from 0 to 4. ");
                                    scanf("%d",&numdependent);
                              }
                            while(!((numdependent==0)||(numdependent==1)||(numdependent==2)||(numdependent==3)||(numdependent==4)));
     
                            dependents=dependentcheck(numdependent); 
        
                            return dependents;
                    }
  
                    else return 0;                   
}

/*
Name: deduct
Purpose: to compute and return the user's personal deductions for income / withholding tax given his information
Pre-conditions: know the user's gross income, validated number of dependents, SSS, philhealth contribution, 
                pagibig contribution, civil status, whether he is the head of the family or not, overtime pay,
                holiday pay, night differential pay, tardy deductions and allowances.  All monetary values among these
                is to be in Philippine Pesos and the remaining values are to be in integers.
Post-conditions: have the user's taxable income in Philippine Pesos
Return value: a double value which is the user's taxable income in Philippine Pesos
Parameters: (into: int dependents, double grossincome, double SSS, double pagibig, double philhealth, int cstatus
                   int head, double overtime, double holiday, double nightdif, double tardy, double allowances) ,
            (out and back to the calling function: double taxable)
*/   
double deduct(double grossincome,int dependents,double SSS,double pagibig,double philhealth, int cstatus, int head, double overtime, double holiday, double nightdif, double tardy, double allowances){
        double taxable/*user's computed taxable income*/;
      
        switch(cstatus)
        {
                case 0: taxable=grossincome-50000; break;
                default: taxable=grossincome-50000;         
        }
      
        switch(head)
        {
                case 0: taxable=taxable; break;
                default: taxable=taxable-50000;         
        }
     
        switch(dependents)
        {
                case 0: taxable=taxable;break;
                case 1: taxable=taxable-25000;break;
                case 2: taxable=taxable-50000;break;
                case 3: taxable=taxable-75000;break;
                case 4: taxable=taxable-100000;break;
                default: taxable=taxable;                                        
        }
     
        taxable=taxable-SSS-pagibig-philhealth+overtime+holiday+nightdif-tardy-allowances;
        return taxable; 
}

/*
Name: computerecto
Purpose: to compute and return the user's withholding tax ,in Philippine Pesos, using the method proposed by Sen. Recto
         on the user's taxable income in Philippine Pesos
Pre-conditions: know the user's taxable income in Philippine Pesos and confirm that the method to be used for computation 
                is indeed Sen. Recto's reform
Post-conditions: have the user's withholding tax in Philippine Pesos
Return value: a double value which is the user's withholding tax in Philippine Pesos
Parameters: (into: double taxable) , (out and back to the calling function: double withholding)
*/   
double computerecto(double taxable){
        double withholding/*user's computed withholding tax*/;  
    
        if(taxable>0&&taxable<=20000)
                withholding=taxable*0.05;
    
        else if(taxable>20000&&taxable<=60000)
                withholding=1000+(taxable-20000)*0.1;
    
        else if(taxable>60000&&taxable<=140000)
                withholding=5000+(taxable-60000)*0.15;
    
        else if(taxable>140000&&taxable<=280000)
                withholding=17000+(taxable-140000)*0.2;
    
        else if(taxable>280000&&taxable<=500000)
                withholding=45000+(taxable-280000)*0.25;
    
        else if(taxable>500000&&taxable<=1000000)
                withholding=100000+(taxable-500000)*0.3;
    
        else if(taxable>1000000)
                withholding=250000+(taxable-1000000)*0.32;   
    
        return withholding;       
}

/*
Name: computeaquino
Purpose: to compute and return the user's withholding tax ,in Philippine Pesos, using the method proposed by Sen. Aquino
         on the user's taxable income in Philippine Pesos
Pre-conditions: know the user's taxable income in Philippine Pesos and confirm that the method to be used for computation 
                is indeed Sen. Aquino's reform
Post-conditions: have the user's withholding tax in Philippine Pesos
Return value: a double value which is the user's withholding tax in Philippine Pesos
Parameters: (into: double taxable) , (out and back to the calling function: double withholding)
*/   
double computeaquino(double taxable){
        double withholding/*user's computed withholding tax*/; 
     
        if(taxable>0&&taxable<=60000)
                withholding=0;
    
        else if(taxable>60000&&taxable<=140000)
                withholding=5000+(taxable-60000)*0.15;
    
        else if(taxable>140000&&taxable<=280000)
                withholding=17000+(taxable-140000)*0.2;
    
        else if(taxable>280000&&taxable<=500000)
                withholding=45000+(taxable-280000)*0.25;
    
        else if(taxable>500000&&taxable<=1000000)
                withholding=100000+(taxable-500000)*0.3;
    
        else if(taxable>1000000&&taxable<=12000000)
                withholding=250000+(taxable-1000000)*0.32;  
    
        else if(taxable>12000000)
                withholding=4000000+(taxable-12000000)*0.35; 
    
        return withholding; 
}

/*
Name: computeangara
Purpose: to compute and return the user's withholding tax ,in Philippine Pesos, using the method proposed by Sen. Angara
         on the user's taxable income in Philippine Pesos
Pre-conditions: know the user's taxable income in Philippine Pesos and confirm that the method to be used for computation 
                is indeed Sen. Angara's reform
Post-conditions: have the user's withholding tax in Philippine Pesos
Return value: a double value which is the user's withholding tax in Philippine Pesos
Parameters: (into: double taxable) , (out and back to the calling function: double withholding)
*/   
double computeangara(double taxable){
        double withholding/*user's computed withholding tax*/; 
   
        if(taxable<=20000)
                withholding=0.00;
       
        else if(taxable>20000&&taxable<=70000)
                withholding=taxable*0.1;
    
        else if(taxable>70000&&taxable<=200000)
                withholding=7000+(taxable-70000)*0.15;
    
        else if(taxable>200000&&taxable<=500000)
                withholding=26500+(taxable-200000)*0.2;
    
        else if(taxable>500000&&taxable<=1000000)
                withholding=86500+(taxable-500000)*0.22;
    
        else if(taxable>1000000)
                withholding=196500+(taxable-1000000)*0.25; 
    
        return withholding; 
}

/*
Name: computecurrent
Purpose: to compute and return the user's withholding tax ,in Philippine Pesos, using the current tax table on the 
         user's taxable income in Philippine Pesos
Pre-conditions: know the user's taxable income in Philippine Pesos and confirm that the method to be used for computation 
                is indeed using the current tax table
Post-conditions: have the user's withholding tax in Philippine Pesos
Return value: a double value which is the user's withholding tax in Philippine Pesos
Parameters: (into: double taxable) , (out and back to the calling function: double withholding)
*/   
double computecurrent(double taxable){
        double withholding/*user's computed withholding tax*/; 
     
        if(taxable>0&&taxable<=10000)
                withholding=taxable*0.05;
    
        else if(taxable>10000&&taxable<=30000)
                withholding=500+(taxable-10000)*0.1;
    
        else if(taxable>30000&&taxable<=70000)
                withholding=2500+(taxable-30000)*0.15;
    
        else if(taxable>70000&&taxable<=140000)
                withholding=8500+(taxable-70000)*0.2;
    
        else if(taxable>140000&&taxable<=250000)
                withholding=22500+(taxable-140000)*0.25;
    
        else if(taxable>250000&&taxable<=500000)
                withholding=50000+(taxable-250000)*0.3;  
    
        else if(taxable>500000)
                withholding=125000+(taxable-500000)*0.32; 
    
        return withholding; 
}

/*
Name: main
Purpose: to facilitate the whole program, call sub routines, scan needed information and print the results, loop the program if 
         need be
Pre-conditions: know the user's information to be entered along with the chosen method for computation
Post-conditions: have the computed and validated values in their respective units, and leave a question asking whether 
                 the program should loop itself for further use; the main function will then react based on the user's response to
                 this question
Return value: none
Parameters: parameters not required to go into main, however, it does pass parameters to sub routines
*/   
int main() {
        int 
        method/*computation method*/, 
        cstatus/*civil status*/, 
        head/*head of the family or not*/,
        dependent/*presence of dependent candidates*/, 
        dependents/*number of validated dependents*/,
        rerun/*whether the main function will iterate itself or not*/, 
        computetype/*employment status*/;
        
        double 
        grossincome/*user's gross income for the month*/,
        SSS/*user's computed SSS contribution for the month*/,
        pagibig/*user's computed Pag-ibig fund contribution for the month*/,
        philhealth/*user's computed Pag-ibig fund contribution for the month*/,
        taxable/*user's computed taxable income for the month*/,
        withholding/*user's computed withholding tax for the month*/,
        overtime/*user's overtime pay for the month*/,
        holiday/*user's holiday pay for the month*/,
        nightdif/*user's night differential pay for the month*/,
        tardy/*user's tardy deductions for the month*/,
        allowances/*user's allowances for the month*/;
    
        do
        {
                printf("\n");
                greet();  
        
                do
                { 
                        printf("\nGross Income(positive peso value or zero): ");
                        scanf("%lf",&grossincome);
                }
                while(grossincome<0);
        
                do
                {
                        printf("\nOvertime Pay(positive peso value or zero): ");
                        scanf("%lf",&overtime);
                }
                while(overtime<0);
        
                do
                {
                        printf("\nHoliday Pay(positive peso value or zero): ");
                        scanf("%lf",&holiday);
                }
                while(holiday<0);
        
                do
                {
                        printf("\nNight Differential(positive peso value or zero): ");
                        scanf("%lf",&nightdif);
                }
                while(nightdif<0);
        
                do
                {
                        printf("\nTardiness Deduction(positive peso value or zero): ");
                        scanf("%lf",&tardy);
                }
                while(tardy<0);
        
                do
                {
                        printf("\nAllowances(positive peso value or zero): ");
                        scanf("%lf",&allowances);
                }
                while(allowances<0);
        
                do
                {
                        printf("\nCivil Status(0 for single, 1 for married): ");
                        scanf("%d",&cstatus);
                }
                while(!((cstatus==0)||(cstatus==1)));
        
                do
                {
                        printf("\nIs the user the head of the family?(0 for not head, 1 for head) ");
                        scanf("%d",&head);  
                }
                while(!((head==0)||(head==1)));
        
                do
                {
                        printf("\nTax to be computed as [0]Employee?  [1]Employer?  [2]OFW?  or [3]Self-employed? ");                             
                        scanf("%d",&computetype);
                }
                while(!((computetype==0)||(computetype==1)||(computetype==2)||(computetype==3)));
        
                do
                {
                        printf("\nAre dependents shouldered? (0 for no, 1 for yes) ");
                        scanf("%d",&dependent);
                }
                while(!((dependent==0)||(dependent==1)));
    
   
                dependents=dependentcount(dependent);
    
                switch(computetype)
                { 
                        case 0: SSS=SSScompEE(grossincome); break;
                        case 1: SSS=SSScompER(grossincome); break;
                        case 2: SSS=SSScompOFW(grossincome); break;
                        case 3: SSS=SSScompSE(grossincome); break;              
                        default: printf("Invalid selection.");
                }
    
                switch(computetype)
                {
                        case 0: pagibig=pagibigcomp(grossincome); break;
                        case 1: pagibig=pagibigcompER(grossincome); break;
                        case 2:
                        case 3: pagibig=pagibigcomp(grossincome); break;    
                        default: printf("Invalid selection.");        
                }
 
    
                switch(computetype)
                { 
                        case 0: 
                        case 1: philhealth=philhealthcomp(grossincome); break;
                        case 2: philhealth=philhealthcompOFW(); break;
                        case 3: philhealth=philhealthcompSE(grossincome); break;              
                        default: printf("Invalid selection.");
                }
    
    
                method=methods();
    
                taxable=deduct(grossincome,dependents,SSS,pagibig,philhealth,cstatus,head,overtime,holiday,nightdif,tardy,allowances);

                switch(method)
                {
                        case 0: withholding=computecurrent(taxable);break;
                        case 1: withholding=computerecto(taxable); break;
                        case 2: withholding=computeaquino(taxable); break; 
                        case 3: withholding=computeangara(taxable); break;
                        default: printf("No valid method selected");  
                }
    
                if(withholding<=0.000000)
                        printf("\nWithholding tax: 0.00 pesos\n"); /*Withholding tax can not be a negative value*/
                else 
                        printf("\nWithholding tax: %.2f pesos\n",withholding);
    
                if(taxable<=0.000000)
                        printf("Taxable income: 0.00 pesos\n"); /*Taxable income can not be a negative value*/
                else 
                        printf("Taxable income: %.2f pesos\n",taxable);
    
                printf("Gross income: %.2f pesos\n",grossincome);
                printf("SSS contribution: %.2f pesos\n",SSS);
                printf("Pag-ibig contribution: %.2f pesos\n",pagibig);
                printf("Philhealth contribution: %.2f pesos\n",philhealth);
                printf("Number of dependents:%d person(s)\n",dependents);
    
                printf("Employment status: ");
                switch(computetype)
                {
                        case 0: printf("Employee\n"); break;
                        case 1: printf("Employer\n"); break;
                        case 2: printf("Overseas Filipino Worker\n"); break;
                        case 3: printf("Self-Employed Individual\n"); break; 
                        default: printf("Invalid.");                
                }
    
                printf("Method used: ");
                switch(method)
                {
                        case 0: printf("Using the tax table\n"); break;
                        case 1: printf("Sen. Recto's reform\n"); break;
                        case 2: printf("Sen. Aquino's reform\n"); break;
                        case 3: printf("Sen. Angara's reform\n"); break; 
                        default: printf("Invalid.");                
                }

                do
                {
                        printf("\nDo you wish to rerun the program? Enter 1 for Yes and 0 for No\n\n");  
                        scanf("%d",&rerun);
                }
                while((rerun!=1)&&(rerun!=0));
    
                printf("________________________________________________________________________________"); 
                /*This line signifies the end of the program*/
    
                if(rerun==0)
                        printf("Press any button on your keyboard to terminate the program.  Thank you!");
                /*This is the parting message before the program terminates itself*/
        }
        while(rerun!=0);   
             
        getch();
        return 0;
}
