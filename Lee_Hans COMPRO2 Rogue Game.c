#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define playericon 'P'
#define delay 2



struct weapondata
{
    char weaponname[31]; 
    int weapondamage;
    int weaponhealth; 
    int weaponvalue; 
    struct weapondata *pnext;
    struct weapondata *pprev;  
};



struct armordata
{
    char armorname[31];  
    int armordefense;
    int armorhealth;  
    int armorvalue;  
    struct armordata *pnext;
    struct armordata *pprev; 
};



struct treasuredata
{
    char treasurename[21];
    int treasurevalue;
    struct treasuredata *pnext;
    struct treasuredata *pprev;
};



struct summonerdata
{
    int level;
    int damage;
    int defense;
    int con;
    int maxHP;
    int remHP;
    int currentxp;
    char playername[9];   
    int credits;
    int roomstravelled;
    struct weapondata *currentweapon;
    struct armordata *currentarmor;
    struct treasuredata *currenttreasure;
};

struct monsterdata
{
    char name[21];
    int damage;
    int health;   
};

struct rdata
{
   char room[9][9];
   int ocurrenceN;
   int ocurrenceS;
   int ocurrenceE;
   int ocurrenceW;  
   int event; 
   struct weapondata *newweapon;
   struct armordata *newarmor;
   struct treasuredata *newtreasure;
   struct monsterdata enemy;
};


struct room
{    
   struct rdata data;
   struct room *pnorth;
   struct room *psouth;
   struct room *peast;
   struct room *pwest;
   int enter; 
   int hospos;
   int vertpos;
   int travelled; 
};

/*
Name: displaytitle
Purpose: display the game's title
Note: "Gimu" is the term made by hardcore players of a "certain mobile RPG" to refer to the publishing company Gumi.
*/
void displaytitle()
{
    
    FILE *ptr;
    char character;
    
    ptr=fopen("title.txt","r");
    while(!feof(ptr))
    {
     fscanf(ptr,"%c",&character);
     printf("%c",character);
    }
    
    getch(); system("cls");
    fclose(ptr);
}



/*
Name: playintro
Purpose: display the introduction to the game's storyline
Note: the value for sleep() below is dependent on the time to be delayed - currently, it is set to 2 or 3 second instances.
*/
void playintro()
{     
     printf(" The year is 21XX...\n"); sleep(delay);
     printf(" In the land of Grand Gaia, a young scientist named Noel helped a certain \n"); sleep(delay);
     printf(" legendary summoner defeat the gods and demons who threatened the land.\n"); sleep(delay); 
     printf(" Aided by a tsundere, a convenient childhood friend, a bipolar goddess,\n"); sleep(delay); 
     printf(" an old, all-knowing veteran, a rich aristocrat, a man with a gigantic ego,\n"); sleep(delay);
     printf(" a long forgotten anti-hero, a stern fighting expert, and an army of waifus, \n"); sleep(delay);
     printf(" the summoner was able to claim victory over the villains of the land.\n"); sleep(delay); 
     printf(" And a time of peace ushered...\n\n\n"); sleep(delay*2);
     printf(" But not for long.\n\n\n"); sleep(delay*2);
     printf(" The researcher Noel craved for more power.\n"); sleep(delay);
     printf(" He sought to rule the world alone, so that no chaos may happen again.\n"); sleep(delay);
     printf(" Some however say that he is only interested in his own utopia,\n"); sleep(delay);
     printf(" a world where only his name is known and worshipped.\n"); sleep(delay);
     printf(" With his army of robotic mock units, this was but a small feat to achieve.\n\n\n"); sleep(delay*2); 
     printf(" Amidst Noel's powers, there was one who stood in his way.\n"); sleep(delay);
     printf(" One who was blessed with the protection of the goddess Tilith.\n"); sleep(delay);
     printf(" One who was once Noel's trusted partner, ally and protector against the gods.\n"); sleep(delay);
     printf(" One who was touted as the enigmatic hero that came from another land.\n"); sleep(delay);
     printf(" One who seeks the rarest item in the world, and use it to overcome Noel.\n"); sleep(delay);
     printf(" One who seeks the legendary summon ticket.\n"); sleep(delay*2);
     printf(" Thus, begins the legendary journey called:\n"); sleep(delay*2);
     system("cls");
}

/*
Name: playexplanation
Purpose: tell the user about the game mechanics
Note: the value for sleep() below is dependent on the time to be delayed - currently, it is set to 2 second instances.
*/
void playexplanation()
{     
     system("cls");     
     printf(" Upon starting the game, the player will have one of each of the following:\n"); sleep(delay);
     printf(" \n-Weapon(boosts damage and health) \n"); sleep(delay);
     printf(" Weapons are the items you use to fight off enemies inside Noel's trial.\n"); sleep(delay);
     printf(" \n-Armor(boosts defense and health) \n"); sleep(delay);
     printf(" Armors are the items you use to soak up enemy attacks.\n"); sleep(delay); 
     printf(" \n-Treasure(can be used to set up save points)\n"); sleep(delay); 
     printf(" Treasures are the items you use go back to the Imperial Capital Randall.\n"); sleep(delay);
     printf(" While these can be sold for currency (zel), \n"); sleep(delay);
     printf(" \n One rule is that the player must, at all times, have at least one variant \n"); sleep(delay);
     printf(" of each of the said items in his / her possession. \n"); sleep(delay); 
     printf(" After all, staying alive is the first priority,  \n"); sleep(delay);
     printf(" and all three types of items are needed to exit the trial safely.  \n"); sleep(delay);  
     
     printf(" \n Saving of data is possible, though with a few changes:  \n"); sleep(delay); 
     printf(" it is only possible with a surface link (treasure set by the player) \n"); sleep(delay); 
     printf(" and when the player has only one of each item type. \n"); sleep(delay); 
     printf(" After all, the surface link can currently only hold so much data. \n"); sleep(delay); 
     printf(" As of now, loading the game will bring the player to the center of a \n"); sleep(delay);
     printf(" room with (4) exits, after which, random room generation will again be used. \n"); sleep(delay);
     
     printf(" \n Also, bosses have thrice the health of normal enemies,  \n"); sleep(delay); 
     printf(" but they become treasure after they are defeated. \n"); sleep(delay); 
     printf(" Legends say that the summon ticket lies in the one-hundreth room. \n"); sleep(delay); 
     printf(" Good luck summoner.  May the blessings of Tilith be with you. \n"); sleep(delay); 
     
}

/*
Name: playending
Purpose: display the ending to the game's storyline, if the player wins
Note: the value for sleep() below is dependent on the time to be delayed - currently, it is set to 2,3 and 5 second instances.
*/
void playending()
{     
     system("cls");
     printf(" After much toil and suffering, the summoner finally arrived\n"); sleep(delay);
     printf(" at the one-hundreth room.\n"); sleep(delay);
     printf(" Floating before the summoner is a summon ticket.\n"); sleep(delay);
     printf(" The same kind which legends say will save the world from Noel.\n"); sleep(delay);
     printf(" The same one which the summoner's allies sacrificed their lives for.\n"); sleep(delay);
     printf(" The same item which countless heroes have sought to obtain. \n"); sleep(delay);
     printf(" Finally, world peace is within reach...\n"); sleep(delay*2);
     
     printf("\n But suddenly, a voice echoed throughout the room:\n"); sleep(delay);
     printf(" 'Good work making it all the way here, my friend.'\n"); sleep(delay);
     printf(" It does not take much to recognize that familiar voice.\n"); sleep(delay);
     printf(" Yes, it belongs to the one and only Noel.\n"); sleep(delay);
     printf(" 'I would love to see more of your exploits within this place,\n"); sleep(delay);
     printf(" but it seems like I can't have you proceed farther.'\n"); sleep(delay);
     printf(" 'This is the end of the line.'\n"); sleep(delay);
     printf(" 'Time to say goodbye to your precious summon ticket...'\n"); sleep(delay*2);
     
     printf("\n At that time, a black hole appeared behind the summoner,\n"); sleep(delay);
     printf(" sucking everything inside it: enemies, items and even the dungeon itself.\n"); sleep(delay);
     printf(" The summoner made a mad dash to grab the summon ticket.\n"); sleep(delay);
     printf(" But it was in vain.  The summoner couldn't reach it.\n"); sleep(delay);
     printf(" So close yet so far, the summoner was sucked inside the black hole too.\n"); sleep(delay);
     printf(" And everything went blank...\n"); sleep(delay*3);
     
     printf("\n A voice was once again heard. \n"); sleep(delay);
     printf(" 'So... how did everything go?'\n"); sleep(delay);
     printf(" The familiar voice came from the one and only Noel!\n"); sleep(delay);
     printf(" 'I hope you enjoyed the grand quest simulation I made.' \n"); sleep(delay);
     printf(" A smiling Noel took off the summoner's virtual-reality helmet.\n"); sleep(delay);
     printf(" The summoner told Noel about the nerve-wracking experience.\n"); sleep(delay);
     printf(" 'What?  I was an evil overlord in the simulation?' \n"""); sleep(delay);
     printf(" 'I don't remember programming things like that...' \n"""); sleep(delay);
     printf(" 'Anyway, off you go.  The world still needs saving after all!' \n"""); sleep(delay*2);
     
     printf(" \n What Noel's plans were after that encounter, \n"); sleep(delay);
     printf(" nobody knows... well, until the next patch comes out. \n"); sleep(delay);
     printf(" Thanks for playing! \n"); sleep(delay); getch();
}

/*
Name: initializestats
Purpose: initialize enemy data (name, damage and health)
*/
void initializestats(struct room *currentroom, struct summonerdata *summoner, int multiplier)
{
     int enemydamage=ceil(randomizer(max(summoner->level-3,0),summoner->level+1)*0.3);
     int enemyhealth=ceil(randomizer(max(summoner->level-5,1),summoner->level));
     int randomval;
     
     currentroom->data.enemy.damage=enemydamage;
     currentroom->data.enemy.health=enemyhealth*multiplier; 
     randomval=randomizer(1,10);
    switch(randomval)
    {
       case 1: strcpy(currentroom->data.enemy.name,"Mock Lucius"); break;
       case 2: strcpy(currentroom->data.enemy.name,"Mock Gazia"); break;
       case 3: strcpy(currentroom->data.enemy.name,"Mock Maxwell"); break;
       case 4: strcpy(currentroom->data.enemy.name,"Mock Cardes"); break;
       case 5: strcpy(currentroom->data.enemy.name,"Mock Zevalhua"); break;
       case 6: strcpy(currentroom->data.enemy.name,"Mock Afla Dilith"); break; 
       case 7: strcpy(currentroom->data.enemy.name,"Mock Xie Jing"); break;
       case 8: strcpy(currentroom->data.enemy.name,"Mock Karl"); break;
       case 9: strcpy(currentroom->data.enemy.name,"Mock Grahdens"); break;
       case 10:strcpy(currentroom->data.enemy.name,"Mock Ark"); break; 
       default: break;
    }       
        
}



/*
Name: dobattle
Purpose: have the player and the enemy deal damage to one another based on their stats
*/
void dobattle(struct summonerdata *summoner, struct room *currentroom)
{
     int enemydamage=max((currentroom->data.enemy.damage)-(summoner->defense),1);
     int summonerdamage=max((summoner->damage),1);
     summoner->remHP-=enemydamage;
     currentroom->data.enemy.health-=summonerdamage;
     
     printf("%s dealt %d damage to %s.\n",summoner->playername,summonerdamage,currentroom->data.enemy.name);
     printf("%s dealt %d damage to %s.\n",currentroom->data.enemy.name,enemydamage,summoner->playername);
}



/*
Name: victorycheck
Purpose: see whether the player or the enemy or none died from the previous battle
*/
int victorycheck(struct summonerdata *summoner, struct room *currentroom)
{
     if((summoner->remHP)<=0)
       return 1;
     else if((currentroom->data.enemy.health)<=0)
       return 2;
     else
       return 0;     
}



/*
Name: checkself
Purpose: displays the player's status and information (including armor, weapon, last treasure sold and credits)
*/
void checkself(struct summonerdata *summoner)
{
     system("cls");
     
     printf("          // Status Report //\n\n");
     printf("Weapon name: %s\n",summoner->currentweapon->weaponname);
     printf("Weapon damage: %d\n",summoner->currentweapon->weapondamage);
     printf("Weapon HP: %d\n",summoner->currentweapon->weaponhealth);
     printf("Weapon value: %d\n\n",summoner->currentweapon->weaponvalue);
     
     printf("Armor name: %s\n",summoner->currentarmor->armorname);
     printf("Armor defense: %d\n",summoner->currentarmor->armordefense);
     printf("Armor HP: %d\n",summoner->currentarmor->armorhealth);
     printf("Armor value: %d\n\n",summoner->currentarmor->armorvalue);
     
     printf("[Current stats:]\n");
     printf("Max Health:%d\n",summoner->maxHP);
     printf("Damage:%d\n",summoner->damage);
     printf("Defense:%d\n",summoner->defense); 
     printf("Con:%d\n\n",summoner->con); 
    
     printf("[Base stats:]\n");
     printf("Max Health:%d\n",summoner->maxHP - summoner->currentweapon->weaponhealth - summoner->currentarmor->armorhealth);
     printf("Damage:%d\n",summoner->damage - summoner->currentweapon->weapondamage);
     printf("Defense:%d\n",summoner->defense - summoner->currentarmor->armordefense); 
     printf("Con:%d\n\n",summoner->con); 
     
     printf("[Credits:]\n");
     printf("Current credits: %d zel\n",summoner->credits);
     
     printf("       // End of Status Report //\n\n");
     
     printf("________________________________________________________________________________");
}



/*
Name: inputcheck
Purpose: see whether an input is valid or not (and return the appropriate value based on the validity of the input)
*/
int inputcheck(char moveinput)
{
    if(moveinput=='a'||moveinput=='w'||moveinput=='s'||moveinput=='d'||
       moveinput=='c'||moveinput=='j'||moveinput=='k'||moveinput=='l')
     return 1;
    else
     return 0;
}



/*
Name: printHP
Purpose: displays the player's health, experience, location and level.  Also checks whether it is time to level up or not.
*/
int printHP(struct summonerdata *summoner, struct room *currentroom)
{

    int bars,i;
    int barsxp;
    int neededxp=ceil((summoner->level)*0.3);
    int xpmax=0;
    
    bars=((summoner->remHP)*10)/(summoner->maxHP);
    barsxp=((summoner->currentxp)*10)/neededxp;
    
    // displays player health in multiple ways (using bars, as a fraction, and as percentage)
    printf("[%s]\nHitpoints:  [",summoner->playername);
    for(i=1; i<=bars; i++)
     printf("/");
    for(bars; bars<10; bars++)
     printf(" ");
    printf("]");
    printf("  [%d / %d (%.2f percent remaining)]\n",(summoner->remHP),(summoner->maxHP),((summoner->remHP)*100.0)/(summoner->maxHP)); 
    
    // displays player experience using bars and player level
    printf("Experience: [");
    for(i=1; i<=barsxp; i++)
     printf("/");
    for(barsxp; barsxp<10; barsxp++)
     printf(" ");
    printf("]\n");
    printf("Summoner level: [%d]\n",summoner->level);
    
    // displays player coordinates, to show and prove the linking of rooms, as well as the number of roomns already discovered
    printf("\nCoordinates:[N:%u | S:%u | E:%u | W:%u | C:%u]\n",currentroom->pnorth,currentroom->psouth,currentroom->peast,currentroom->pwest,currentroom);
    printf("Rooms Traversed: [%d]\n",summoner->roomstravelled);
    printf("________________________________________________________________________________\n"); 
    
    xpmax=0; // tells us whether the player has maxed experience or not at this point in time
    
    if(summoner->currentxp==neededxp)
     xpmax++;
 
    return xpmax;
}



/*
Name: statallocate
Purpose: tell the player about basic game controls and facilitate the initial allocation of player, weapon, 
         armor and treasure status
*/  
void statallocate(struct summonerdata *summoner)
{
int points=0;
char marker[5]={'>',' ',' ',' ',' '};
char stats[5][8]={{"level  "},{"damage "},{"defense"},{"con    "},{"HP     "}};
int statval[5]={0,0,0,0,0};
char input;
int location=0;
int i;
int gosignal=0; // tells the program when the count for the player's allocated points matches the 7 points to be used
     
     do
      {
       printf(" Summoner, what is your name? [Max: 8 characters] ");
       scanf("%s",&summoner->playername);
      } 
      while(strlen(summoner->playername)>=9);

        do 
        {
          system("cls");
          printf("Stats allocating time!  You have 7 points to spend.  Choose wisely!\n\n");  
      
          for (i=0; i<5; i++)
           {  
             printf("%c   %s  [%d / 7]",marker[i],stats[i],statval[i]);
             printf("\n");
           } 
     
          printf("\nBy the way, basic controls for the game include:\n");
          printf("(w) - move up\n(a) - move left\n(s) - move down\n(d) - move right\n(c) - check self\n(j) - open weapon inventory\n(k) - open armor inventory\n(l) - open treasure inventory\n"); 
   
          input=getch();
   
          if(points==7)
             gosignal++;
    
          switch(input)
          {
            case 'w': if(location>0)
                      {
                         marker[location]=' ';
                         location--;
                         marker[location]='>'; 
                      }  break; 
                
            case 'a': if(statval[location]>0)
                      {
                         statval[location]--;
                         points--;
                      }  break;
          
            case 's': if(location<4)
                      {
                         marker[location]=' ';
                         location++;
                         marker[location]='>'; 
                      }  break; 
                
            case 'd': if(statval[location]<7) 
                      {
                         statval[location]++;
                         points++;
                      }  break;
               
            default: break;                              
          }    
       } while(gosignal==0); 

      summoner->level = statval[0];
      summoner->damage = statval[1];
      summoner->defense = statval[2];
      summoner->con = statval[3];
      summoner->maxHP = statval[4];

      summoner->maxHP+=summoner->level;                
      summoner->remHP=summoner->maxHP;
      
      summoner->damage+=ceil(0.8*summoner->level);
      summoner->defense+=ceil(0.2*summoner->level);
      summoner->con+=ceil(0.2*summoner->level);
      
      summoner->credits=0;
      summoner->currentweapon=malloc(sizeof(struct weapondata));
      summoner->currentarmor=malloc(sizeof(struct armordata));
      summoner->currenttreasure=malloc(sizeof(struct treasuredata));
      
      strcpy(summoner->currentweapon->weaponname,"Standard-Issue-Forceblaster"); 
      summoner->currentweapon->weapondamage=1;
      summoner->currentweapon->weaponhealth=1;
      summoner->currentweapon->weaponvalue=2;
      summoner->currentweapon->pnext=NULL;
      summoner->currentweapon->pprev=NULL;
      
      strcpy(summoner->currentarmor->armorname,"Standard-Issue-Salvager-Uniform"); 
      summoner->currentarmor->armordefense=1;
      summoner->currentarmor->armorhealth=2;
      summoner->currentarmor->armorvalue=3;
      summoner->currentarmor->pnext=NULL;
      summoner->currentarmor->pprev=NULL;
      
      strcpy(summoner->currenttreasure->treasurename,"Sentimental-Necklace"); 
      summoner->currenttreasure->treasurevalue=10;
      summoner->currenttreasure->pnext=NULL;
      summoner->currenttreasure->pprev=NULL;
      
      summoner->maxHP+=summoner->currentweapon->weaponhealth;
      summoner->damage+=summoner->currentweapon->weapondamage; 
      summoner->maxHP+=summoner->currentarmor->armorhealth;
      summoner->defense+=summoner->currentarmor->armordefense; 
      
}



/*
Name: newweaponinitialize
Purpose: initialize status of a newly acquired weapon 
Note: ideas for weapon names were inspired by the weapons of the legendary 6 heroes :)
*/
void newweaponinitialize(struct room *currentroom, struct summonerdata *summoner)
{
    char weaponprefix[15];
    char weaponsuffix[15];
    int randomval, randomval2;
    int damagehigh;
    int damagelow;
    
    damagelow=ceil((summoner->level)*0.1);
    damagehigh=ceil((summoner->level)*0.5);
    
    currentroom->data.newweapon=malloc(sizeof(struct weapondata));
    
    currentroom->data.newweapon->weapondamage=randomizer(damagelow,damagehigh); 
    currentroom->data.newweapon->weaponvalue=randomizer(max((summoner->level-3),0),summoner->level)*10; 
    currentroom->data.newweapon->weaponhealth=randomizer(1,5);
    
    randomval=randomizer(0,5);
    randomval2=randomizer(6,11);
    
    switch(randomval)
    {
       case 0: strcpy(weaponprefix,"Novice-"); break;
       case 1: strcpy(weaponprefix,"Old-"); break;
       case 2: strcpy(weaponprefix,"Abyssal-"); break;
       case 3: strcpy(weaponprefix,"Powerful-"); break;
       case 4: strcpy(weaponprefix,"Legendary-"); break;
       case 5: strcpy(weaponprefix,"Divine-"); break;  
       default: break;
    }
   
   
   switch(randomval2)
   {
       case 6: strcpy(weaponsuffix,"Dandelga"); break;
       case 7: strcpy(weaponsuffix,"Lexida"); break;
       case 8: strcpy(weaponsuffix,"Drevas"); break;
       case 9: strcpy(weaponsuffix,"Batootha"); break;
       case 10: strcpy(weaponsuffix,"Urias"); break;
       case 11: strcpy(weaponsuffix,"Leomurg"); break; 
       default: break; 
   }
    
    strcpy(currentroom->data.newweapon->weaponname , weaponprefix); 
    strcat(currentroom->data.newweapon->weaponname , weaponsuffix);
    
    currentroom->data.newweapon->pprev=NULL;
    currentroom->data.newweapon->pnext=NULL;    
}


/*
Name: newarmorinitialize
Purpose: initialize status of a newly acquired armor
Note: ideas for armor names were inspired by the Six Armors Series :)
*/
void newarmorinitialize(struct room *currentroom, struct summonerdata *summoner)
{
    char armorprefix[15];
    char armorsuffix[15];
    int randomval, randomval2;
    int defensehigh;
    int defenselow;
    
    defenselow=ceil((summoner->level)*0.1);
    defensehigh=ceil((summoner->level)*0.7);
    
    currentroom->data.newarmor=malloc(sizeof(struct armordata));
    
    currentroom->data.newarmor->armordefense=randomizer(defenselow,defensehigh);
    currentroom->data.newarmor->armorvalue=randomizer(max((summoner->level-3),0),summoner->level+1)*10;
    currentroom->data.newarmor->armorhealth=randomizer(1,5);
    

    randomval=randomizer(0,5);
    randomval2=randomizer(6,11);
    
    switch(randomval)
    {
       case 0: strcpy(armorprefix,"Ancient-"); break;
       case 1: strcpy(armorprefix,"Luminous-"); break;
       case 2: strcpy(armorprefix,"Hellfire-"); break;
       case 3: strcpy(armorprefix,"Sacred-"); break;
       case 4: strcpy(armorprefix,"Refurbished-"); break;
       case 5: strcpy(armorprefix,"Advanced-"); break;  
       default: break;
    }
   
   
   switch(randomval2)
   {
       case 6: strcpy(armorsuffix,"Beiorg"); break;
       case 7: strcpy(armorsuffix,"Lafdranya"); break;
       case 8: strcpy(armorsuffix,"Vishra"); break;
       case 9: strcpy(armorsuffix,"Reeze"); break;
       case 10: strcpy(armorsuffix,"Melchio"); break;
       case 11: strcpy(armorsuffix,"Nemethgear"); break; 
       default: break; 
   }
   
       
    strcpy(currentroom->data.newarmor->armorname , armorprefix); 
    strcat(currentroom->data.newarmor->armorname , armorsuffix);    
    
    currentroom->data.newarmor->pprev=NULL;
    currentroom->data.newarmor->pnext=NULL;
}



/*
Name: newtreasureinitialize
Purpose: generates the treasure's name and value, then sells it immediately. It updates the player's currency count afterwards.
Note: ideas for treasure names were inspired by the various types of items in a certain mobile game :)
*/
void newtreasureinitialize(struct room *currentroom, struct summonerdata *summoner)
{
    char treasureprefix[15];
    char treasuresuffix[15];
    int randomval, randomval2;
    
    currentroom->data.newtreasure=malloc(sizeof(struct treasuredata));
    
    randomval=randomizer(0,5);
    randomval2=randomizer(6,11);
      
     switch(randomval)
    {
       case 0: strcpy(treasureprefix,"Heresy-"); break;
       case 1: strcpy(treasureprefix,"Fallacy-"); break;
       case 2: strcpy(treasureprefix,"Impiety-"); break;
       case 3: strcpy(treasureprefix,"Infidelity-"); break;
       case 4: strcpy(treasureprefix,"Schism-"); break;
       case 5: strcpy(treasureprefix,"Golden-"); break;  
       default: break;
    }
   
   
   switch(randomval2)
   {
       case 6: strcpy(treasuresuffix,"Orb"); break;
       case 7: strcpy(treasuresuffix,"Gem"); break;
       case 8: strcpy(treasuresuffix,"Seal"); break;
       case 9: strcpy(treasuresuffix,"Idol"); break;
       case 10: strcpy(treasuresuffix,"Tonic"); break;
       case 11: strcpy(treasuresuffix,"Flute"); break; 
       default: break; 
   }
   
       
    strcpy(currentroom->data.newtreasure->treasurename , treasureprefix); 
    strcat(currentroom->data.newtreasure->treasurename , treasuresuffix);  
    
    currentroom->data.newtreasure->treasurevalue=randomizer(summoner->level,summoner->level+5)*10;
    
    currentroom->data.newtreasure->pprev=NULL;
    currentroom->data.newtreasure->pnext=NULL;

}

/*
Name: loadroom
Purpose: generates the room's information based on the save file.
Note: this function places the player in a room similar to the starting one, with four exits (one on each side) 
      but with a surface link in the middle
*/
void loadroom(struct room *ptemp)
{
   int i,j;
     
   for(i=0; i<9; i++)
     for(j=0; j<9; j++)
       if(j==0 || j==8)
         ptemp->data.room[i][j]='|';        
       else
         ptemp->data.room[i][j]=' ';        
     
     
    for(j=0; j<9; j++)
     {
      ptemp->data.room[0][j]='-';
      ptemp->data.room[8][j]='-';
     }
        
     ptemp->data.room[0][4]='#';
     ptemp->data.room[8][4]='#';
     ptemp->data.room[4][0]='#';
     ptemp->data.room[4][8]='#'; 
     ptemp->data.room[4][4]='S';
        
     ptemp->data.ocurrenceN=0;
     ptemp->data.ocurrenceS=0;
     ptemp->data.ocurrenceE=0;
     ptemp->data.ocurrenceW=0;  
     
     ptemp->pnorth=NULL;
     ptemp->psouth=NULL;
     ptemp->peast=NULL;
     ptemp->pwest=NULL;
}

/*
Name: initializeroom
Purpose: generates the room's information, as well as the event in it (monster encounter, armor encounter, etc.).
*/
void initializeroom(struct room *ptemp, struct summonerdata *summoner, int enterfrom)
{
   int i,j;
   
   ptemp->enter=enterfrom; // the direction the player came from, for more logical room exit generation  
   ptemp->data.event=randomizer(1,14);
     
   for(i=0; i<9; i++)
     for(j=0; j<9; j++)
       if(j==0 || j==8)
         ptemp->data.room[i][j]='|';        
       else
         ptemp->data.room[i][j]=' ';        
     
     
    for(j=0; j<9; j++)
     {
      ptemp->data.room[0][j]='-';
      ptemp->data.room[8][j]='-';
     }
     
     ptemp->data.room[8][4]='#'; 
     ptemp->data.room[4][8]='#'; 
     ptemp->data.room[0][4]='#'; 
     ptemp->data.room[4][0]='#'; 
     
     switch(ptemp->data.event)
     {
       case 1: ptemp->data.room[8][4]='-'; ptemp->data.room[4][0]='|'; break;
       case 2: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='A'; break;
       case 3: ptemp->data.room[4][8]='|'; ptemp->data.room[0][4]='-'; break;
       case 4: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='E'; ptemp->data.room[0][4]='-'; break;
       case 5: ptemp->data.room[4][0]='|'; break;
       case 6: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='W'; ptemp->data.room[8][4]='-'; break;
       case 7: ptemp->data.room[0][4]='-'; ptemp->data.room[8][4]='-'; break; 
       case 8: ptemp->data.room[4][8]='|'; ptemp->data.room[0][4]='-'; break;
       case 9: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='B'; ptemp->data.room[4][8]='|'; ptemp->data.room[8][4]='-';break;
       case 10: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='E'; ptemp->data.room[4][0]='|'; break;
       case 11: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='W'; ptemp->data.room[4][8]='|'; ptemp->data.room[8][4]='-'; break;
       case 12: break;
       case 13: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='A'; ptemp->data.room[0][4]='-'; break;
       case 14: ptemp->data.room[ptemp->data.event/2][ptemp->data.event/2]='T'; ptemp->data.room[8][4]='-'; ptemp->data.room[4][0]='|'; break;                                                              
       default: ptemp->data.room[8][4]='-'; break;                       
     }
     
     switch(enterfrom) // the direction the player entered from can not be blocked - that would be illogical to an extent
     {
       case 0: ptemp->data.room[8][4]='#'; 
               ptemp->data.room[4][8]='#'; 
               ptemp->data.room[0][4]='#'; 
               ptemp->data.room[4][0]='#'; break;
       case 1: ptemp->data.room[8][4]='#'; break;
       case 2: ptemp->data.room[4][8]='#'; break;
       case 3: ptemp->data.room[0][4]='#'; break;
       case 4: ptemp->data.room[4][0]='#'; break;
       default: break;               
     }   

     // These lines check whether the player has visited rooms of the 4 cardinal directions with respect to the current room.
     // This information will be used for room mechanics.
     ptemp->data.ocurrenceN=0;
     ptemp->data.ocurrenceS=0;
     ptemp->data.ocurrenceE=0;
     ptemp->data.ocurrenceW=0;  
     
     ptemp->pnorth=NULL;
     ptemp->psouth=NULL;
     ptemp->peast=NULL;
     ptemp->pwest=NULL;
     
     if((ptemp->data.event==4)||(ptemp->data.event==10)) // Monster
       initializestats(ptemp,summoner,1);

     else if((ptemp->data.event==14)) // Treasure
       newtreasureinitialize(ptemp,summoner);
       
     else if((ptemp->data.event==2)||(ptemp->data.event==13)) // Armor
       newarmorinitialize(ptemp,summoner);
       
     else if((ptemp->data.event==6)||(ptemp->data.event==11)) // Weapon
       newweaponinitialize(ptemp,summoner);
       
     else if((ptemp->data.event==9)) // Boss Monster
       initializestats(ptemp,summoner,3);
     
       
     ptemp->travelled=0;         
}

/*
Name: levelup
Purpose: increases the player's level, resets the player's experience to zero, and adjusts the player's stats accordingly
*/
int levelup(struct summonerdata *summoner, int ocurrence)
{ 
    summoner->damage-=ceil(0.8*summoner->level);
    summoner->defense-=ceil(0.2*summoner->level);
    summoner->con-=ceil(0.2*summoner->level);
    
    summoner->currentxp=0;
    summoner->level+=1;
    
    summoner->damage+=ceil(0.8*summoner->level);
    summoner->defense+=ceil(0.2*summoner->level);
    summoner->con+=ceil(0.2*summoner->level);
    summoner->maxHP+=1;  
    
    if(ocurrence==0)  // First level up
    {
     summoner->remHP=summoner->maxHP;
     ocurrence++;
    }   
    
    return ocurrence;  // Subsequent level up(s)
}


/*
Name: max
Purpose: returns the larger of the two integer values passed on to it
*/
int max(int val1, int val2)
{
    if(val1>val2)
     return val1;
    else
     return val2; 
}



/*
Name: randomizer
Purpose: returns a random integer between the two values passed on to it.
*/
int randomizer(int lowerlimit, int upperlimit)
{
    int number;
    
    srand(time(NULL));
    
    do
     number=rand()%(upperlimit+1);
    while(number<lowerlimit || number>upperlimit);
     
    return number; 
}

/*
Name: printroom
Purpose: prints the player's current location
*/
void printroom(struct room *currentroom)
{
  int i,j;
        
     for(i=0; i<9; i++)
       {
       printf("   ");        
       for(j=0; j<9; j++)
        printf(" %c",currentroom->data.room[i][j]);
       printf("\n"); 
       }        
}
  
/*
Name: surfacelink
Purpose: handles how the player interacts with the surface link
*/
void surfacelink(struct summonerdata *summoner, struct room *currentroom)
{
     char command;
     struct summonerdata *ptemp=malloc(sizeof(struct summonerdata));
     struct summonerdata *ptrail=malloc(sizeof(struct summonerdata));
     int i;
     
     summoner->remHP=summoner->maxHP;
     printf("%s has been healed to full health.\n",summoner->playername);
     
     ptemp->currentweapon=summoner->currentweapon;
     ptemp->currentarmor=summoner->currentarmor;
     ptemp->currenttreasure=summoner->currenttreasure;
     
     system("cls");
     printf("Welcome to the surface link, please input your command for it.\n");
     printf("(w) - sell weapon\n");
     printf("(a) - sell armor\n");
     printf("(t) - sell treasure\n");
     printf("(s) - save game\n"); 
     printf("(any other key) - close surface link\n"); 
     
     command=getch();  
     
     // Weapon interaction
     if(command=='w')
     {
     system("cls");                               
     do{   
     printf("Weapon Selling:  Use (a) or (d) to traverse.\nUse (s) to sell.\nUse (any other key) to close.\n");                  
     printf("\nName:[%s]\nDamage:[%d]\nHealth:[%d]\nValue:[%d]",ptemp->currentweapon->weaponname,
            ptemp->currentweapon->weapondamage,ptemp->currentweapon->weaponhealth,ptemp->currentweapon->weaponvalue);
     command=getch();
     system("cls");       
     
       switch(command)
       {
         case 'a': if(ptemp->currentweapon->pprev!=NULL)
                     ptemp->currentweapon=ptemp->currentweapon->pprev;
                     
                   else if(ptemp->currentweapon->pprev==NULL)  
                     printf("This is the front end of the list.  Please try another command.\n");
                     
                   break;
                   
         case 'd': if(ptemp->currentweapon->pnext!=NULL)
                     ptemp->currentweapon=ptemp->currentweapon->pnext;
                     
                   else if(ptemp->currentweapon->pnext==NULL)  
                     printf("This is the back end of the list.  Please try another command.\n"); 
                      
                   break; 
                   
         case 's': if(summoner->currentweapon==ptemp->currentweapon)
                    printf("Please do not sell what you are currently holding.  Unequip it first.\n");
              
                   else if(summoner->currentweapon!=ptemp->currentweapon)
                   { 
                    if(ptemp->currentweapon->pprev!=NULL && ptemp->currentweapon->pnext!=NULL)  
                    {    
                      ptrail->currentweapon=ptemp->currentweapon->pprev;
                      ptrail->currentweapon->pnext=ptemp->currentweapon->pnext;
                      ptemp->currentweapon->pnext->pprev=ptrail->currentweapon;
                      printf("Sold the %s for %d zel.\n",ptemp->currentweapon->weaponname,ptemp->currentweapon->weaponvalue);
                      summoner->maxHP-=summoner->currentweapon->weaponhealth;
                      summoner->damage-=summoner->currentweapon->weapondamage;
                      summoner->credits+=ptemp->currentweapon->weaponvalue;
                      ptemp->currentweapon=NULL;
                      ptemp->currentweapon=ptrail->currentweapon;
                      summoner->maxHP+=ptemp->currentweapon->weaponhealth;
                      summoner->damage+=ptemp->currentweapon->weapondamage;
                    }
                    
                    else if(ptemp->currentweapon->pprev==NULL)  
                    {    
                      ptrail->currentweapon=ptemp->currentweapon->pnext;
                      ptrail->currentweapon->pprev=NULL;
                      printf("Sold the %s for %d zel.\n",ptemp->currentweapon->weaponname,ptemp->currentweapon->weaponvalue);
                      summoner->maxHP-=summoner->currentweapon->weaponhealth;
                      summoner->damage-=summoner->currentweapon->weapondamage;
                      summoner->credits+=ptemp->currentweapon->weaponvalue;
                      ptemp->currentweapon=NULL;
                      ptemp->currentweapon=ptrail->currentweapon;
                      summoner->maxHP+=ptemp->currentweapon->weaponhealth;
                      summoner->damage+=ptemp->currentweapon->weapondamage;
                    }
                    
                    else if(ptemp->currentweapon->pnext==NULL)  
                    {    
                      ptrail->currentweapon=ptemp->currentweapon->pprev;
                      ptrail->currentweapon->pnext=NULL;
                      printf("Sold the %s for %d zel.\n",ptemp->currentweapon->weaponname,ptemp->currentweapon->weaponvalue);
                      summoner->maxHP-=summoner->currentweapon->weaponhealth;
                      summoner->damage-=summoner->currentweapon->weapondamage;
                      summoner->credits+=ptemp->currentweapon->weaponvalue;
                      ptemp->currentweapon=NULL;
                      ptemp->currentweapon=ptrail->currentweapon;
                      summoner->maxHP+=ptemp->currentweapon->weaponhealth;
                      summoner->damage+=ptemp->currentweapon->weapondamage;
                    }   
                                     
                   }  
                   break; 
                   
          default: break; 
                   }                 
     }while(command=='s' || command=='a' || command=='d');                         
     }
     
     //Armor interaction
     else if(command=='a')
     {
     system("cls");     
        do{   
     printf("Armor selling:  Use (a) or (d) to traverse.\nUse (s) to sell. \nUse (any other key) to close.\n");                  
     printf("\nName:[%s]\nDefense:[%d]\nHealth:[%d]\nValue:[%d]",ptemp->currentarmor->armorname,
            ptemp->currentarmor->armordefense,ptemp->currentarmor->armorhealth,ptemp->currentarmor->armorvalue);
     command=getch();
     system("cls");       
       
       switch(command)
       {
         case 'a': if(ptemp->currentarmor->pprev!=NULL)
                     ptemp->currentarmor=ptemp->currentarmor->pprev;
                     
                   else if(ptemp->currentarmor->pprev==NULL)  
                     printf("This is the front end of the list.  Please try another command.\n");
                     
                   break;
                   
         case 'd': if(ptemp->currentarmor->pnext!=NULL)
                     ptemp->currentarmor=ptemp->currentarmor->pnext;
                     
                   else if(ptemp->currentarmor->pnext==NULL)  
                     printf("This is the back end of the list.  Please try another command.\n"); 
                      
                   break;
                   
         case 's': if(summoner->currentarmor==ptemp->currentarmor)
                    printf("Please do not sell what you are currently holding.  Unequip it first.\n");
              
                   else if(summoner->currentarmor!=ptemp->currentarmor)
                   { 
                    if(ptemp->currentarmor->pprev!=NULL && ptemp->currentarmor->pnext!=NULL)  
                    {    
                      ptrail->currentarmor=ptemp->currentarmor->pprev;
                      ptrail->currentarmor->pnext=ptemp->currentarmor->pnext;
                      ptemp->currentarmor->pnext->pprev=ptrail->currentarmor;
                      printf("Sold the %s for %d zel.\n",ptemp->currentarmor->armorname,ptemp->currentarmor->armorvalue);
                      summoner->maxHP-=summoner->currentarmor->armorhealth;
                      summoner->defense-=summoner->currentarmor->armordefense;
                      summoner->credits+=ptemp->currentarmor->armorvalue;
                      ptemp->currentarmor=NULL;
                      ptemp->currentarmor=ptrail->currentarmor;
                      summoner->maxHP+=ptemp->currentarmor->armorhealth;
                      summoner->defense+=ptemp->currentarmor->armordefense;
                    }
                    
                    else if(ptemp->currentarmor->pprev==NULL)  
                    {    
                      ptrail->currentarmor=ptemp->currentarmor->pnext;
                      ptrail->currentarmor->pprev=NULL;
                      printf("Sold the %s for %d zel.\n",ptemp->currentarmor->armorname,ptemp->currentarmor->armorvalue);
                      summoner->maxHP-=summoner->currentarmor->armorhealth;
                      summoner->defense-=summoner->currentarmor->armordefense;
                      summoner->credits+=ptemp->currentarmor->armorvalue;
                      ptemp->currentarmor=NULL;
                      ptemp->currentarmor=ptrail->currentarmor;
                      summoner->maxHP+=ptemp->currentarmor->armorhealth;
                      summoner->defense+=ptemp->currentarmor->armordefense;
                    }
                    
                    else if(ptemp->currentarmor->pnext==NULL)  
                    {    
                      ptrail->currentarmor=ptemp->currentarmor->pprev;
                      ptrail->currentarmor->pnext=NULL;
                      printf("Sold the %s for %d zel.\n",ptemp->currentarmor->armorname,ptemp->currentarmor->armorvalue);
                      summoner->maxHP-=summoner->currentarmor->armorhealth;
                      summoner->defense-=summoner->currentarmor->armordefense;
                      summoner->credits+=ptemp->currentarmor->armorvalue;
                      ptemp->currentarmor=NULL;
                      ptemp->currentarmor=ptrail->currentarmor;
                      summoner->maxHP+=ptemp->currentarmor->armorhealth;
                      summoner->defense+=ptemp->currentarmor->armordefense;
                    }
                    
                   }      
                   break; 
                   
                   default: break; 
                   }  
     }while(command=='d' || command=='a' || command=='s');         
     }
     
     //Treasure interaction
     else if(command=='t')
     {
     system("cls");     
     do{   
     printf("Treasure selling:  \nUse (a) or (d) to traverse. \nUse(s) sell. \nUse (any other key) to close.\n");                  
     printf("\nName:[%s]\nValue:[%d]",ptemp->currenttreasure->treasurename,ptemp->currenttreasure->treasurevalue);
     if(ptemp->currenttreasure->pprev==NULL && ptemp->currenttreasure->pnext==NULL) 
      printf("\n\nOnly one piece of treasure left.  Selling is disabled for now.\n");  
     command=getch();
     system("cls");       
       
    if(ptemp->currenttreasure->pprev==NULL && ptemp->currenttreasure->pnext==NULL)                                    
       command='p'; 
          
       switch(command)
       {
         case 'a': if(ptemp->currenttreasure->pprev!=NULL)
                     ptemp->currenttreasure=ptemp->currenttreasure->pprev;
                     
                   else if(ptemp->currenttreasure->pprev==NULL)  
                     printf("This is the front end of the list.  Please try another command.\n");
                     
                   break;
                   
         case 'd': if(ptemp->currenttreasure->pnext!=NULL)
                     ptemp->currenttreasure=ptemp->currenttreasure->pnext;
                     
                   else if(ptemp->currenttreasure->pnext==NULL)  
                     printf("This is the back end of the list.  Please try another command.\n"); 
                      
                   break;
                   
         case 's': if(ptemp->currenttreasure->pprev!=NULL && ptemp->currenttreasure->pnext!=NULL)  
                    {    
                      ptrail->currenttreasure=ptemp->currenttreasure->pprev;
                      ptrail->currenttreasure->pnext=ptemp->currenttreasure->pnext;
                      ptemp->currenttreasure->pnext->pprev=ptrail->currenttreasure;
                      printf("Sold the %s for %d zel.\n",ptemp->currenttreasure->treasurename,ptemp->currenttreasure->treasurevalue);
                      summoner->credits+=ptemp->currenttreasure->treasurevalue;
                      ptemp->currenttreasure=NULL;
                      ptemp->currenttreasure=ptrail->currenttreasure;
                    }
                    
                    else if(ptemp->currenttreasure->pprev==NULL && ptemp->currenttreasure->pnext!=NULL)  
                    {    
                      ptrail->currenttreasure=ptemp->currenttreasure->pnext;
                      ptrail->currenttreasure->pprev=NULL;
                      printf("Sold the %s for %d zel.\n",ptemp->currenttreasure->treasurename,ptemp->currenttreasure->treasurevalue);
                      summoner->credits+=ptemp->currenttreasure->treasurevalue;
                      ptemp->currenttreasure=NULL;
                      ptemp->currenttreasure=ptrail->currenttreasure;
                    }
                    
                    else if(ptemp->currenttreasure->pnext==NULL && ptemp->currenttreasure->pprev!=NULL)  
                    {    
                      ptrail->currenttreasure=ptemp->currenttreasure->pprev;
                      ptrail->currenttreasure->pnext=NULL;
                      printf("Sold the %s for %d zel.\n",ptemp->currenttreasure->treasurename,ptemp->currenttreasure->treasurevalue);
                      summoner->credits+=ptemp->currenttreasure->treasurevalue;
                      ptemp->currenttreasure=NULL;
                      ptemp->currenttreasure=ptrail->currenttreasure;
                    }  
                    
                   summoner->currenttreasure=ptemp->currenttreasure;   
                   break; 
                   
                  default: break;  
                  }            
     }while(command=='a' || command=='d' || command=='s');          
     }
     
     //Attempt to save the game
     else if(command=='s' && summoner->currentweapon->pprev==NULL && summoner->currentweapon->pnext==NULL &&
                             summoner->currentarmor->pprev==NULL  && summoner->currentarmor->pnext==NULL  &&
                             summoner->currenttreasure->pprev==NULL && summoner->currenttreasure->pnext==NULL)
     {
     system("cls"); 
     FILE *pSavedata;
     FILE *pSaveweapon;
     FILE *pSavearmor;
     FILE *pSavetreasure;
       
     pSavedata=fopen("savefile.txt", "w");
     pSaveweapon=fopen("saveweapon.txt","w");
     pSavearmor=fopen("savearmor.txt","w");
     pSavetreasure=fopen("savetreasure.txt","w");

      if(pSavedata!=NULL)
       {
         printf("Slot found.  Saving...\n"); 
          
         fprintf(pSavedata,"%d %d %d %d %d %d %d %d %d %s",
                                                          summoner->level,summoner->damage,summoner->defense,summoner->con,
                                                          summoner->maxHP,summoner->remHP, summoner->currentxp,summoner->credits,
                                                          summoner->roomstravelled,summoner->playername                                                          
                                                          );  
                                                           
         fprintf(pSaveweapon,"%d %d %d %s",summoner->currentweapon->weapondamage, summoner->currentweapon->weaponhealth, 
                                           summoner->currentweapon->weaponvalue, summoner->currentweapon->weaponname);
                                           
         fprintf(pSavearmor,"%d %d %d %s",summoner->currentarmor->armordefense, summoner->currentarmor->armorhealth, 
                                           summoner->currentarmor->armorvalue, summoner->currentarmor->armorname);
                                           
         fprintf(pSavetreasure,"%d %s",summoner->currenttreasure->treasurevalue, summoner->currenttreasure->treasurename);                                   
                                                          
                                             
         
         printf("Save data successful.\n");
       }
            
      else
         printf("No save file found.  Save cancelled. \n");
         
     fclose(pSavedata);
     fclose(pSaveweapon);
     fclose(pSavearmor);
     fclose(pSavetreasure);   
     }
     
     //Blocks the player from saving (if conditions were not followed somehow)
     else if(command=='s' && summoner->currentweapon->pprev!=NULL || summoner->currentweapon->pnext!=NULL ||
                             summoner->currentarmor->pprev!=NULL  || summoner->currentarmor->pnext!=NULL  ||
                             summoner->currenttreasure->pprev!=NULL || summoner->currenttreasure->pnext!=NULL)
      printf("You can only bring one weapon, one armor and one treasure with you \n as you save the game."  
             "Not like you can carry a whole trove of items with you \n as the surface link can't accommodate them all.\n\n");
}

/*
Name: checkempty
Purpose: checks whether the current room is empty or not
*/
int checkempty (struct room *currentroom)
{
   int i,j;
   int roomempty=1;
   
    for (i=1; i<=8; i++)
     for (j=1; j<=8; j++)
      if (currentroom->data.room[i][j] == 'W' || currentroom->data.room[i][j] == 'A' || currentroom->data.room[i][j] == 'T' ||
          currentroom->data.room[i][j] == 'E' || currentroom->data.room[i][j] == 'B' || currentroom->data.room[i][j] == 'S')
          {
             printf("Room is not empty, failed to set up surface link."); sleep(1);
             roomempty=0;  
          }  
        
   return roomempty;
}

/*
Name: weaponinventory
Purpose: handles the management of the player's weapons and equipping them.
*/
void weaponinventory(struct summonerdata *summoner)
{
     char command;
     struct summonerdata *ptemp=malloc(sizeof(struct summonerdata));
     struct summonerdata *ptrail=malloc(sizeof(struct summonerdata));
     
     ptemp->currentweapon=summoner->currentweapon;
     
     do{   
     printf("Welcome to the weapon inventory.  Use (a) or (d) to traverse.\nUse (w) to equip.\nUse (any other key) to close.\n");                  
     printf("\nName:[%s]\nDamage:[%d]\nHealth:[%d]\nValue:[%d]",ptemp->currentweapon->weaponname,
            ptemp->currentweapon->weapondamage,ptemp->currentweapon->weaponhealth,ptemp->currentweapon->weaponvalue);
     command=getch();
     system("cls");       
       
       switch(command)
       {
         case 'a': if(ptemp->currentweapon->pprev!=NULL)
                     ptemp->currentweapon=ptemp->currentweapon->pprev;
                     
                   else if(ptemp->currentweapon->pprev==NULL)  
                     printf("This is the front end of the list.  Please try another command.\n");
                     
                   break;
                   
         case 'd': if(ptemp->currentweapon->pnext!=NULL)
                     ptemp->currentweapon=ptemp->currentweapon->pnext;
                     
                   else if(ptemp->currentweapon->pnext==NULL)  
                     printf("This is the back end of the list.  Please try another command.\n"); 
                      
                   break; 
                   
         case 'w': summoner->maxHP-=summoner->currentweapon->weaponhealth;
                   summoner->damage-=summoner->currentweapon->weapondamage;
    
                   summoner->maxHP+=ptemp->currentweapon->weaponhealth;
                   summoner->damage+=ptemp->currentweapon->weapondamage;
     
                   if((summoner->remHP) > (summoner->maxHP))
                    summoner->remHP=summoner->maxHP;
              
                   summoner->currentweapon=ptemp->currentweapon;
         
                   printf("Equipped the %s as weapon.\n",ptemp->currentweapon->weaponname);
                   
                   break;
                   
           
                                                           
         default: break;             
       }
       
       if(summoner->remHP>summoner->maxHP)
        summoner->remHP=summoner->maxHP;
        
     }while(command=='w' || command=='a' || command=='d'); 
}

/*
Name: armorinventory
Purpose: handles the management of the player's armor and equipping them.
*/
void armorinventory(struct summonerdata *summoner)
{
     char command;
     struct summonerdata *ptemp=malloc(sizeof(struct summonerdata));
     struct summonerdata *ptrail=malloc(sizeof(struct summonerdata));
     
     ptemp->currentarmor=summoner->currentarmor;
    
     do{   
     printf("Welcome to the armor inventory.  Use (a) or (d) to traverse.\nUse (w) to equip. \nUse (any other key) to close.\n");                  
     printf("\nName:[%s]\nDefense:[%d]\nHealth:[%d]\nValue:[%d]",ptemp->currentarmor->armorname,
            ptemp->currentarmor->armordefense,ptemp->currentarmor->armorhealth,ptemp->currentarmor->armorvalue);
     command=getch();
     system("cls");       
       
       switch(command)
       {
         case 'a': if(ptemp->currentarmor->pprev!=NULL)
                     ptemp->currentarmor=ptemp->currentarmor->pprev;
                     
                   else if(ptemp->currentarmor->pprev==NULL)  
                     printf("This is the front end of the list.  Please try another command.\n");
                     
                   break;
                   
         case 'd': if(ptemp->currentarmor->pnext!=NULL)
                     ptemp->currentarmor=ptemp->currentarmor->pnext;
                     
                   else if(ptemp->currentarmor->pnext==NULL)  
                     printf("This is the back end of the list.  Please try another command.\n"); 
                      
                   break; 
                   
         case 'w': summoner->maxHP-=summoner->currentarmor->armorhealth;
                   summoner->defense-=summoner->currentarmor->armordefense;
    
                   summoner->maxHP+=ptemp->currentarmor->armorhealth;
                   summoner->defense+=ptemp->currentarmor->armordefense;
     
                   if((summoner->remHP) > (summoner->maxHP))
                    summoner->remHP=summoner->maxHP;
              
                   summoner->currentarmor=ptemp->currentarmor;
         
                   printf("Equipped the %s as armor.\n",ptemp->currentarmor->armorname);
                   
                   break;
                   
                                                           
         default: break;             
       }
       
       if(summoner->remHP>summoner->maxHP)
        summoner->remHP=summoner->maxHP;
        
     }while(command=='w' || command=='a' || command=='d'); 
}

/*
Name: treasureinventory
Purpose: handles the management of the player's treasures and turning them into surface links.
*/
void treasureinventory(struct summonerdata *summoner, struct room *currentroom)
{
     char command;
     struct summonerdata *ptemp=malloc(sizeof(struct summonerdata));
     struct summonerdata *ptrail=malloc(sizeof(struct summonerdata));
     
     ptemp->currenttreasure=summoner->currenttreasure;
    
     do{   
     printf("Welcome to the treasure inventory.  \nUse (a) or (d) to traverse. \nUse (s) to set up a surface link. \nUse (any other key) to close.\n");                  
     printf("\nName:[%s]\nValue:[%d]",ptemp->currenttreasure->treasurename,ptemp->currenttreasure->treasurevalue);
     if(ptemp->currenttreasure->pprev==NULL && ptemp->currenttreasure->pnext==NULL) 
      printf("\n\nOnly one piece of treasure left.  Making a surface link is disabled for now.\n");  
     command=getch();
     system("cls");       
       
    if(ptemp->currenttreasure->pprev==NULL && ptemp->currenttreasure->pnext==NULL)                                    
       command='p'; 
          
       switch(command)
       {
         case 'a': if(ptemp->currenttreasure->pprev!=NULL)
                     ptemp->currenttreasure=ptemp->currenttreasure->pprev;
                     
                   else if(ptemp->currenttreasure->pprev==NULL)  
                     printf("This is the front end of the list.  Please try another command.\n");
                     
                   break;
                   
         case 'd': if(ptemp->currenttreasure->pnext!=NULL)
                     ptemp->currenttreasure=ptemp->currenttreasure->pnext;
                     
                   else if(ptemp->currenttreasure->pnext==NULL)  
                     printf("This is the back end of the list.  Please try another command.\n"); 
                      
                   break; 
                   
         case 's':  if(checkempty(currentroom)==1)
                    {
                     if(currentroom->data.room[currentroom->hospos][currentroom->vertpos]==' ' && 
                         !(currentroom->hospos==4 && currentroom->vertpos==4))
                      {
                        if(ptemp->currenttreasure->pprev!=NULL && ptemp->currenttreasure->pnext!=NULL)  
                        {    
                          ptrail->currenttreasure=ptemp->currenttreasure->pprev;
                          ptrail->currenttreasure->pnext=ptemp->currenttreasure->pnext;
                          ptemp->currenttreasure->pnext->pprev=ptrail->currenttreasure;
                          ptemp->currenttreasure=NULL;
                          ptemp->currenttreasure=ptrail->currenttreasure;
                        }
                    
                        else if(ptemp->currenttreasure->pprev==NULL && ptemp->currenttreasure->pnext!=NULL)  
                        {    
                          ptrail->currenttreasure=ptemp->currenttreasure->pnext;
                          ptrail->currenttreasure->pprev=NULL;
                          ptemp->currenttreasure=NULL;
                          ptemp->currenttreasure=ptrail->currenttreasure;
                        }
                    
                        else if(ptemp->currenttreasure->pnext==NULL && ptemp->currenttreasure->pprev!=NULL)  
                        {    
                          ptrail->currenttreasure=ptemp->currenttreasure->pprev;
                          ptrail->currenttreasure->pnext=NULL;
                          ptemp->currenttreasure=NULL;
                          ptemp->currenttreasure=ptrail->currenttreasure;
                        }                                     
                        currentroom->data.room[4][4]='S';
                      }  
                      
                     else
                      {
                        printf("Unable to place the surface link in the center of the room.\n");
                        printf("It gets the most reception from there :)\n"); 
                      }  
                    }
                     
                    summoner->currenttreasure=ptemp->currenttreasure;  
                    break;
         
         default: break;
        
       }          
                   
     }while(command=='a' || command=='d'); 
}

/*
Name: savescore
Purpose: handles the management of the highscores of all players
*/
void savescore (struct summonerdata *summoner)
{
     FILE *pscore;
     char name[9];
     int score;
     
     int scoretobeat=-1;
     int currentop=0;
     int numberofpeople=0;
     int i;
     int numtop=0;
     int numrem;
     char nametobeat[9];
     
     // Add player to list
     pscore=fopen("scores.txt","a");
     fprintf(pscore,"%s %d ",summoner->playername,summoner->credits);
     fclose(pscore);
     
     system("cls");
     
     printf("           <<List of all players>>\n\n");
     
     //Get top scorer and print whole list
     pscore=fopen("scores.txt","r");
     while(!(feof(pscore)))
     {
      fscanf(pscore,"%s %d ",&name,&score);
      numberofpeople++;
      printf("  Player name: [%s]  / Score: [%d]\n",name,score);
      if(score>scoretobeat)
      {
       scoretobeat=score;
       strcpy(nametobeat,name);
      }
     }
     fclose(pscore);
     
     pscore=fopen("scores.txt","r");
     while(!(feof(pscore)))
     {
      fscanf(pscore,"%s %d ",&name,&score);
      if(score==scoretobeat)
        numtop++;  
     }
     fclose(pscore); 
      
     printf("\n");
     
     if(numtop>10)
      numtop=10;
     
     if(numberofpeople>10)
       numrem=10-numtop;
     else
       numrem=numberofpeople-numtop;
     
     printf("To see the list of the top 10 summoners of all time, please press any character.\n");
     getch();
     
     system("cls");
     printf("           <<All Time High - Scorers>>\n\n"); 
     
     //Print top scorers
     pscore=fopen("scores.txt","r");
     while(numtop>0 && !(feof(pscore)))
     {
      fscanf(pscore,"%s %d ",&name,&score);              
      if(score==scoretobeat)
      {
       strcpy(nametobeat,name);
       printf("  Current Top Player: [%s] with %d points!\n",nametobeat,scoretobeat);
       numtop--;
      }
     }
      fclose(pscore);
      currentop=scoretobeat;
     
     //Everyone else who were among the top 10 scorers
     while(numrem>0)
     {               
     //Get new score to beat
     scoretobeat=-1;
     numtop=0;
     pscore=fopen("scores.txt","r");
     while(!(feof(pscore)))
     {
      fscanf(pscore,"%s %d ",&name,&score);
      if(score>scoretobeat && score<currentop)
        scoretobeat=score;
     }
     fclose(pscore); 
     
     //Print all the next in line for high score
     pscore=fopen("scores.txt","r");
     while(!(feof(pscore)))
     {
      fscanf(pscore,"%s %d ",&name,&score);
      if(score==scoretobeat)
      {
       strcpy(nametobeat,name);                     
       printf("  Among the top 10 high-scorers is: [%s] with %d points!\n",nametobeat,scoretobeat); 
       numtop++;
      }
     }
     fclose(pscore); 
     
     numrem-=numtop; 
     currentop=scoretobeat;            
     }
        
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

/*
Name: main
Purpose: facilitates use of other functions, facilitates moving and printing of the map as well
*/
int main()
{
    
    int i,j,canmove,xpmax;
    int game=0;
    int ocurrence=0;
    char newgame;
    char userinput;
    struct summonerdata summoner;
    struct room *currentroom;
    struct monsterdata enemy;
    struct summonerdata holder;
    
    struct summonerdata *ptemp;
    struct summonerdata *ptemp2;
    FILE *pSavedata;
    FILE *pSaveweapon;
    FILE *pSavearmor;
    FILE *pSavetreasure;
    int levelcopy;
    int damagecopy;
    int defensecopy;
    int concopy;
    int maxHPcopy;
    int remHPcopy;
    int currentxpcopy;
    int creditscopy;
    int roomstravelledcopy;
    char playernamecopy[9];
    struct room *currentroomcopy;
    char weaponnamecopy[31];
    int weapondamagecopy;
    int weaponhealthcopy;
    int weaponvaluecopy;
    char armornamecopy[31];
    int armordefensecopy;
    int armorhealthcopy;
    int armorvaluecopy;
    char treasurenamecopy[21];
    int treasurevaluecopy;
    
    playintro();
    displaytitle();
    
    do
    {
      printf("To start a new game, press (n), to continue from the save file, press (c).\n");
      newgame=getch();
    } while(newgame!='n' && newgame!='c');
    
    
    // loading of data starts here
    if(newgame=='c')
    {
     ocurrence=1;
         
      pSavedata=fopen("savefile.txt","r");
      pSaveweapon=fopen("saveweapon.txt","r");
      pSavearmor=fopen("savearmor.txt","r");
      pSavetreasure=fopen("savetreasure.txt","r");
      
      if (pSavedata!=NULL)
      {
      printf(" Saved file found.  Loading...\n");
      fscanf(pSavedata,"%d %d %d %d %d %d %d %d %d %s %d %s %d %d %d %s %d %d %d %s %d ",
                                                          &levelcopy,&damagecopy,&defensecopy,&concopy,
                                                          &maxHPcopy,&remHPcopy,&currentxpcopy,&creditscopy,
                                                          &roomstravelledcopy,&playernamecopy,&currentroomcopy                                                        
                                                          ); 
                                                          
      fscanf(pSaveweapon,"%d %d %d %s ",&weapondamagecopy,&weaponhealthcopy,&weaponvaluecopy,&weaponnamecopy);
      fscanf(pSavearmor,"%d %d %d %s ",&armordefensecopy,&armorhealthcopy,&armorvaluecopy,&armornamecopy);
      fscanf(pSavetreasure,"%d %s ",&treasurevaluecopy,&treasurenamecopy); 
      
                                               
     summoner.level=levelcopy; 
     summoner.damage=damagecopy;
     summoner.defense=defensecopy;
     summoner.con=concopy;
     summoner.maxHP=maxHPcopy; 
     summoner.remHP=remHPcopy;
     summoner.currentxp=currentxpcopy; 
     summoner.credits=creditscopy; 
     summoner.roomstravelled=roomstravelledcopy; 
     strcpy(summoner.playername,playernamecopy);
     
     
     summoner.currentweapon=malloc(sizeof(struct weapondata));
     summoner.currentarmor=malloc(sizeof(struct armordata));
     summoner.currenttreasure=malloc(sizeof(struct treasuredata));
     
     strcpy(summoner.currentweapon->weaponname,weaponnamecopy);
     summoner.currentweapon->weapondamage=weapondamagecopy;
     summoner.currentweapon->weaponhealth=weaponhealthcopy;
     summoner.currentweapon->weaponvalue=weaponvaluecopy;
     summoner.currentweapon->pnext=NULL;
     summoner.currentweapon->pprev=NULL;
     
     strcpy(summoner.currentarmor->armorname,armornamecopy);
     summoner.currentarmor->armordefense=armordefensecopy;
     summoner.currentarmor->armorhealth=armorhealthcopy;
     summoner.currentarmor->armorvalue=armorvaluecopy;
     summoner.currentarmor->pnext=NULL;
     summoner.currentarmor->pprev=NULL;
     
     strcpy(summoner.currenttreasure->treasurename,treasurenamecopy);
     summoner.currenttreasure->treasurevalue=treasurevaluecopy;
     summoner.currenttreasure->pnext=NULL;
     summoner.currenttreasure->pprev=NULL;

     
     currentroom=malloc(sizeof(struct room)); 
     currentroom->hospos=5; 
     currentroom->vertpos=4;  
     currentroom->travelled=1;  
     
     loadroom(currentroom);
     currentroom->data.room[currentroom->hospos][currentroom->vertpos]=playericon;
     
     
     }
     
     else
     {
       printf("No save file found.  Proceeding as new game.\n");
       newgame='n';
     }
       
     fclose(pSavedata);
     fclose(pSaveweapon);
     fclose(pSavearmor);
     fclose(pSavetreasure);
    }
    // loading of data ends here
    // new game initialization starts here
    if(newgame=='n')
    {              
      statallocate(&summoner); printf(" \n");
      playexplanation(); 
      ocurrence=levelup(&summoner,ocurrence);
      currentroom=malloc(sizeof(struct room));
      initializeroom(currentroom,&summoner,0);
      summoner.roomstravelled=1;
      currentroom->hospos=5;
      currentroom->vertpos=4;
      currentroom->data.room[currentroom->hospos][currentroom->vertpos]=playericon;
    }
    // new game initialization ends hare
    
    //Scanning of input - for the user's next action
    do
    {
     game=0;
           
      do
      {
        printf("\nGame in progress...awaiting further input.\n");
        userinput=getch();
        canmove=inputcheck(userinput);               
      }
      while(canmove=0);
    
   
   //Basically, the loop which governs the entire game
   system("cls");
   
   if(currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='#')                   
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]=' ';
       
     switch(userinput)
     {
      case 'w': if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]==' ')
                 {
                  currentroom->hospos-=1;
                  if(currentroom->travelled)
                   currentroom->travelled++;
                 }
                  
                else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='#')
                  {
                    if(currentroom->data.ocurrenceN==0)
                    {                                                                     
                     struct room *ptemp=malloc(sizeof(struct room));
                     initializeroom(ptemp,&summoner,1);            
                     currentroom->data.ocurrenceN=1; 
                     currentroom->pnorth=ptemp;   
                     ptemp->psouth=currentroom;
                     ptemp->data.ocurrenceS=1;
                     currentroom=ptemp;
                     currentroom->travelled++;
                    }
                    
                    else
                    {
                     currentroom=currentroom->pnorth;
                     currentroom->travelled++;
                    }
                     
                    currentroom->hospos=7;
                    currentroom->vertpos=4;
                                                        
                  }
                  
                  else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='E' ||
                          currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='B')
                  {
                    dobattle(&summoner,currentroom); 
                    game=victorycheck(&summoner,currentroom); 
                  }
                
                else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='W')
                 {
                  holder.currentweapon=summoner.currentweapon;
                  while(summoner.currentweapon->pnext!=NULL)
                   summoner.currentweapon=summoner.currentweapon->pnext;
                  summoner.currentweapon->pnext=currentroom->data.newweapon;
                  currentroom->data.newweapon->pprev=summoner.currentweapon;
                  summoner.currentweapon=holder.currentweapon;
                  holder.currentweapon=NULL;
                  currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='A')
                 {
                  holder.currentarmor=summoner.currentarmor;
                  while(summoner.currentarmor->pnext!=NULL)
                   summoner.currentarmor=summoner.currentarmor->pnext;
                  summoner.currentarmor->pnext=currentroom->data.newarmor;
                  currentroom->data.newarmor->pprev=summoner.currentarmor;
                  summoner.currentarmor=holder.currentarmor;
                  holder.currentarmor=NULL;
                  currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='T')
                 {
                  summoner.currentxp++;
                  summoner.remHP+=summoner.con;
                  if((summoner.remHP) > (summoner.maxHP))
                  summoner.remHP=summoner.maxHP;
                  
                  holder.currenttreasure=summoner.currenttreasure;
                  while(summoner.currenttreasure->pnext!=NULL)
                   summoner.currenttreasure=summoner.currenttreasure->pnext;
                  summoner.currenttreasure->pnext=currentroom->data.newtreasure;
                  currentroom->data.newtreasure->pprev=summoner.currenttreasure;
                  summoner.currenttreasure=holder.currenttreasure;
                  holder.currenttreasure=NULL;
                  currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='S')
                 {    
                  surfacelink(&summoner, currentroom); // surface link
                 }
                  
                  if(game==2)
                  {
                  summoner.remHP=summoner.remHP+summoner.con;
                  if(summoner.remHP>summoner.maxHP)
                   summoner.remHP=summoner.maxHP;
                   
                  printf("%s has defeated %s.\n",summoner.playername,currentroom->data.enemy.name);
                  summoner.currentxp++; 
                  if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='E')        
                  currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=' ';
                  
                  else if(currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]=='B')
                  {        
                   currentroom->data.room[currentroom->hospos-1][currentroom->vertpos]='T';
                   newtreasureinitialize(currentroom,&summoner);
                  }
                  }
                                 
                break;
                
      case 'a': if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]==' ')
                 {
                 currentroom->vertpos-=1;
                 if(currentroom->travelled)
                   currentroom->travelled++;
                 }
                else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='#')
                  {
                   if(currentroom->data.ocurrenceW==0)
                    {                                                                        
                    struct room *ptemp=malloc(sizeof(struct room));
                    initializeroom(ptemp,&summoner,2);
                    currentroom->data.ocurrenceW=1; 
                    currentroom->pwest=ptemp;
                    ptemp->peast=currentroom;
                    ptemp->data.ocurrenceE=1;
                    currentroom=ptemp;
                    currentroom->travelled++;
                    }
                    
                    else
                    {
                     currentroom=currentroom->pwest;
                     currentroom->travelled++;
                    }
                      
                    currentroom->hospos=4;
                    currentroom->vertpos=7;
                                                                
                  }  
                  
                  else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='E' ||
                          currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='B')
                  {
                    dobattle(&summoner,currentroom); 
                    game=victorycheck(&summoner,currentroom); 
                  }
                  
                  else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='W')
                 {                            
                  holder.currentweapon=summoner.currentweapon;
                  while(summoner.currentweapon->pnext!=NULL)
                   summoner.currentweapon=summoner.currentweapon->pnext;     
                  summoner.currentweapon->pnext=currentroom->data.newweapon;
                  currentroom->data.newweapon->pprev=summoner.currentweapon;
                  summoner.currentweapon=holder.currentweapon;
                  holder.currentweapon=NULL;
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='A')
                 {
                  holder.currentarmor=summoner.currentarmor;
                  while(summoner.currentarmor->pnext!=NULL)
                   summoner.currentarmor=summoner.currentarmor->pnext;
                  summoner.currentarmor->pnext=currentroom->data.newarmor;
                  currentroom->data.newarmor->pprev=summoner.currentarmor;
                  summoner.currentarmor=holder.currentarmor;
                  holder.currentarmor=NULL;
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='T')
                 {
                  summoner.currentxp++;
                  summoner.remHP+=summoner.con;
                  if((summoner.remHP) > (summoner.maxHP))
                  summoner.remHP=summoner.maxHP;
                  
                  holder.currenttreasure=summoner.currenttreasure;
                  while(summoner.currenttreasure->pnext!=NULL)
                   summoner.currenttreasure=summoner.currenttreasure->pnext;
                  summoner.currenttreasure->pnext=currentroom->data.newtreasure;
                  currentroom->data.newtreasure->pprev=summoner.currenttreasure;
                  summoner.currenttreasure=holder.currenttreasure;
                  holder.currenttreasure=NULL;
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='S')
                 {
                  surfacelink(&summoner, currentroom); //surface link
                 }
                 
                  if(game==2)
                  {
                  summoner.remHP=summoner.remHP+summoner.con;
                  if(summoner.remHP>summoner.maxHP)
                   summoner.remHP=summoner.maxHP;
                   
                   
                  printf("%s has defeated %s.\n",summoner.playername,currentroom->data.enemy.name);
                  summoner.currentxp++;     
                  if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='E')    
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=' ';
                  else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]=='B') 
                  {       
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos-1]='T';
                  newtreasureinitialize(currentroom,&summoner);
                  }
                  
                  }         
                break;
                
      case 's': if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]==' ')              
                  {
                  currentroom->hospos+=1;
                  if(currentroom->travelled)
                   currentroom->travelled++;
                  } 
                else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='#')
                  {
                   if(currentroom->data.ocurrenceS==0)
                    {                                                                     
                    struct room *ptemp=malloc(sizeof(struct room));
                    initializeroom(ptemp,&summoner,3);
                    currentroom->data.ocurrenceS=1;    
                    currentroom->psouth=ptemp;
                    ptemp->pnorth=currentroom;
                    ptemp->data.ocurrenceN=1;
                    currentroom=ptemp;
                    currentroom->travelled++;
                    }
                    
                    else
                    {
                     currentroom=currentroom->psouth;
                     currentroom->travelled++;
                    }
                     
                    currentroom->hospos=1;
                    currentroom->vertpos=4;
                                                          
                  }
                  
                  else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='E' ||
                          currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='B')
                  {
                    dobattle(&summoner,currentroom); 
                    game=victorycheck(&summoner,currentroom); 
                  }
                  
                  else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='W')
                 {
                  holder.currentweapon=summoner.currentweapon;    
                  while(summoner.currentweapon->pnext!=NULL)
                   summoner.currentweapon=summoner.currentweapon->pnext;     
                  summoner.currentweapon->pnext=currentroom->data.newweapon;
                  currentroom->data.newweapon->pprev=summoner.currentweapon;
                  summoner.currentweapon=holder.currentweapon;
                  holder.currentweapon=NULL;
                  currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='A')
                 {
                  holder.currentarmor=summoner.currentarmor;
                  while(summoner.currentarmor->pnext!=NULL)
                   summoner.currentarmor=summoner.currentarmor->pnext;
                  summoner.currentarmor->pnext=currentroom->data.newarmor;
                  currentroom->data.newarmor->pprev=summoner.currentarmor;
                  summoner.currentarmor=holder.currentarmor;
                  holder.currentarmor=NULL;
                  currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='T')
                 {
                  summoner.currentxp++;
                  summoner.remHP+=summoner.con;
                  if((summoner.remHP) > (summoner.maxHP))
                  summoner.remHP=summoner.maxHP;
                  
                  holder.currenttreasure=summoner.currenttreasure;
                  while(summoner.currenttreasure->pnext!=NULL)
                   summoner.currenttreasure=summoner.currenttreasure->pnext;
                  summoner.currenttreasure->pnext=currentroom->data.newtreasure;
                  currentroom->data.newtreasure->pprev=summoner.currenttreasure;
                  summoner.currenttreasure=holder.currenttreasure;
                  holder.currenttreasure=NULL;
                  currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='S')
                 {
                 surfacelink(&summoner, currentroom); //surface link
                 }
                 
                  if(game==2)
                  {
                  summoner.remHP=summoner.remHP+summoner.con;
                  if(summoner.remHP>summoner.maxHP)
                   summoner.remHP=summoner.maxHP;
                   
                  printf("%s has defeated %s.\n",summoner.playername,currentroom->data.enemy.name);
                  summoner.currentxp++; 
                  if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='E')       
                  currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=' ';
                  else if(currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]=='B')  
                  {      
                  currentroom->data.room[currentroom->hospos+1][currentroom->vertpos]='T';
                  newtreasureinitialize(currentroom,&summoner);
                  }
                  }           
                break;
                
      case 'd': if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]==' ')            
                  {
                  currentroom->vertpos+=1;
                  if(currentroom->travelled)
                   currentroom->travelled++;
                  } 
                else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='#')
                  {
                  if(currentroom->data.ocurrenceE==0)
                    {
                    struct room *ptemp=malloc(sizeof(struct room)); 
                    initializeroom(ptemp,&summoner,4);
                    currentroom->data.ocurrenceE=1; 
                    currentroom->peast=ptemp;
                    ptemp->pwest=currentroom;
                    ptemp->data.ocurrenceW=1;
                    currentroom=ptemp;
                    currentroom->travelled++;
                    }
                    
                    else
                    {
                     currentroom=currentroom->peast;
                     currentroom->travelled++;
                    }
                     
                    currentroom->hospos=4;
                    currentroom->vertpos=1;
                                                             
                  }
                  
                  else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='E' ||
                          currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='B')
                  {
                    dobattle(&summoner,currentroom); 
                    game=victorycheck(&summoner,currentroom); 
                  }
                  
                  else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='W')
                 {
                  holder.currentweapon=summoner.currentweapon;
                  while(summoner.currentweapon->pnext!=NULL)
                   summoner.currentweapon=summoner.currentweapon->pnext;     
                  summoner.currentweapon->pnext=currentroom->data.newweapon;
                  currentroom->data.newweapon->pprev=summoner.currentweapon;
                  summoner.currentweapon=holder.currentweapon;
                  holder.currentweapon=NULL;
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='A')
                 {
                  holder.currentarmor=summoner.currentarmor;
                  while(summoner.currentarmor->pnext!=NULL)
                   summoner.currentarmor=summoner.currentarmor->pnext;
                  summoner.currentarmor->pnext=currentroom->data.newarmor;
                  currentroom->data.newarmor->pprev=summoner.currentarmor;
                  summoner.currentarmor=holder.currentarmor;
                  holder.currentarmor=NULL;
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='T')
                 {
                  summoner.currentxp++;
                  summoner.remHP+=summoner.con;
                  if((summoner.remHP) > (summoner.maxHP))
                  summoner.remHP=summoner.maxHP;
                  
                  holder.currenttreasure=summoner.currenttreasure;
                  while(summoner.currenttreasure->pnext!=NULL)
                   summoner.currenttreasure=summoner.currenttreasure->pnext;
                  summoner.currenttreasure->pnext=currentroom->data.newtreasure;
                  currentroom->data.newtreasure->pprev=summoner.currenttreasure;
                  summoner.currenttreasure=holder.currenttreasure;
                  holder.currenttreasure=NULL;
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=' ';
                 }
                 
                 else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='S')
                 {
                  surfacelink(&summoner, currentroom); //surface link
                 }
                  
                  if(game==2)
                  {
                  summoner.remHP=summoner.remHP+summoner.con;
                  if(summoner.remHP>summoner.maxHP)
                   summoner.remHP=summoner.maxHP;
                              
                  printf("%s has defeated %s.\n",summoner.playername,currentroom->data.enemy.name);
                  summoner.currentxp++;  
                  
                  if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='E')       
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=' ';
                  
                  else if(currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]=='B')  
                  {     
                  currentroom->data.room[currentroom->hospos][currentroom->vertpos+1]='T';
                  newtreasureinitialize(currentroom,&summoner);
                  }
                  }               
                break;
                
      case 'c': checkself(&summoner); break;
      case 'j': weaponinventory(&summoner); break;
      case 'k': armorinventory (&summoner); break;
      case 'l': treasureinventory (&summoner, currentroom); break;
                
      default: break;             
     }
     
     if(currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='#' &&
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='E' &&
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='B' &&
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='T' &&
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='W' &&
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='A' &&
        currentroom->data.room[currentroom->hospos][currentroom->vertpos]!='S')
        
         currentroom->data.room[currentroom->hospos][currentroom->vertpos]=playericon;
        
     if(currentroom->travelled==1)
      summoner.roomstravelled++;
     
    //Print Stats
     xpmax=printHP(&summoner, currentroom);
     if(xpmax==1)
      ocurrence=levelup(&summoner,ocurrence);

     
    //Print Room
    printroom(currentroom); 
    
    }  
    while(game!=1 && summoner.roomstravelled<101);
    
    if(summoner.roomstravelled>=101) // game won
     playending();
    
    if(game==1) // game lost
     printf("The summoner has lost. Noel's trials prevents the use of gems to revive as well.\nBetter luck next time.");
     
     savescore(&summoner);
  //Game proper ends here...
    getch();
    return 0;
}



     
