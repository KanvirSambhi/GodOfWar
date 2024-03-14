//ALL CREDIT TO THE STORY GOES TO THE VIDEO GAME GOD OF WAR BY PLAY STATION SANTA MONICA STUDIOS

//Kanvir Sambhi

//CIS-5 HYBO

//June 5, 2023

//Final Project

#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

const int HEAL_STONE = 25;

struct Kratos //Main Player
{
    double kratosHealth;
    int leviathanAxeMinimum;
    int leviathanAxeMaximum;
    int axeRange;
    int axeHits;
    int axeSpecialMaximum;
    int axeSpecialMinimum;
    int bladesOfChaosMinimum;
    int bladesOfChaosMaximum;
    int bladesRange;
    int bladesSpeedMinimum;
    int bladesSpeedMaximum;
    int bladesSpecial;
    double shield;
    int heals;
};

struct Atreus //Side Character/Extra Attacks
{
    int bow;
    int arrowDamage;
};

struct Drauger //Main Enemy Type
{
    int draugerHealthMaximum;
    int draugerHealthMinimum;
    int minimumAttack;
    int maximumAttack;
};

//Prototypes
void introductoryMessage();
void gameScript(int i, Drauger draugerClasses[], Kratos kratosClasses[], Atreus atreusClasses[]);
void mainStoryLine();
void deathMessage();
void agilityClass(Kratos kratosClasses[], Drauger draugerClasses[], Atreus atreusClasses[]);
void strengthClass(Kratos kratosClasses[], Drauger draugerClasses[], Atreus atreusClasses[]);
void defenseClass(Kratos kratosClasses[], Drauger draugerClasses[], Atreus atreusClasses[]);
void winnerMessage();

//Main Method
int main()
{
    //Variables
    int choice;

    //Declaring Arrays
    Kratos kratosClasses[3];
    Atreus atreusClasses[3];
    Drauger draugerClasses[1];

    //Intro Menu and Message
    introductoryMessage();

    //Input to different class types
    cin >> choice;

    mainStoryLine();
    //Input Checking
    while (choice < 1 || choice > 3)
    {
        cout << "Please select a valid class choice." << endl;
        cin >> choice;
    };


    //Class Types
    if (choice == 1)
    {
        agilityClass(kratosClasses, draugerClasses, atreusClasses);
    }

    else if (choice == 2)
    {
        strengthClass(kratosClasses, draugerClasses, atreusClasses);
    }
    else
    {
        defenseClass(kratosClasses, draugerClasses, atreusClasses);
    }


    return 0;
}



void agilityClass(Kratos kratosClasses[], Drauger draugerClasses[], Atreus atreusClasses[])
{
    //Array input for gameScript
    int i = 0;

    //Array preinput for gameScript
    kratosClasses[0] = { 350, 20, 30, 15, 4, 5, 6, 10, 15, 5, 6, 9, 13, .25, 4 };
    atreusClasses[0] = { 4, 10 };
    gameScript(i, draugerClasses, kratosClasses, atreusClasses);

}

void strengthClass(Kratos kratosClasses[], Drauger draugerClasses[], Atreus atreusClasses[])
{
    //Array input for gameScript
    int i = 1;

    //Array preinput for gameScript
    kratosClasses[1] = { 400, 30, 40, 30, 1, 7, 7, 15, 20, 15, 4, 7, 14, .50, 6 };
    atreusClasses[1] = { 5, 10 };
    gameScript(i, draugerClasses, kratosClasses, atreusClasses);
}

void defenseClass(Kratos kratosClasses[], Drauger draugerClasses[], Atreus atreusClasses[])
{
    //Array input for gameScript
    int i = 2;

    //Array preinput for gameScript
    kratosClasses[2] = { 500, 10, 20, 20, 2, 4, 4, 5, 10, 10, 3, 6, 8, .75, 3 };
    atreusClasses[2] = { 8, 10 };
    gameScript(i,draugerClasses, kratosClasses, atreusClasses);
}

void gameScript(int i, Drauger draugerClasses[], Kratos kratosClasses[], Atreus atreusClasses[])
{
    //Variables
    int selection;
    int draugerAmount;
    int draugerCount = 0;
    int f = 0;

    //Array Calls
    draugerClasses[f] = { 200, 100, 20, 30 };
    kratosClasses[i];
    atreusClasses[i];

    //Drauger Amount to fight
    cout << "Choose from 10-20 on how many Drauger you would like to face off against, some amounts may be difficult and possibly impossible" << endl;
    cin >> draugerAmount;

    //Drauger Input Check
    while (draugerAmount < 10 && draugerAmount > 20)
    {
        cout << "Please input a valid amount for the amount of Draugers." << endl;
        cin >> draugerAmount;
    };
    do
    {
        //Resetting Cool-down and Initializing next Drauger Health
        int axeSpecialCooldown = 5;
        int bladesSpecialCooldown = 5;
        int draugerHealth = draugerClasses[f].draugerHealthMinimum + (rand() % draugerClasses[f].draugerHealthMaximum);
        do
        {

            cout << "Choose a move with a number, and press enter:      1. Axe Main Attack   2. Axe Special Attack   3. Blades Main Attack" << endl;
            cout << "                                                   4. Blades Special Attack    5. Deflect   6. Heal   7. Atreus' Arrows" << endl;
            cout << "Kratos Health: " << kratosClasses[i].kratosHealth << "   Atreus Arrows: " << atreusClasses[i].bow << "   Healing Stones: " << kratosClasses[i].heals << endl;
            cout << "Drauger Killed: " << draugerCount << "     Drauger Left: " << draugerAmount << "     Current Drauger Health: " << draugerHealth << endl << endl;

            cin >> selection;
            while ((selection < 0 || selection > 7) || (selection == 2 && axeSpecialCooldown < 5) ||
                   (selection == 4 && bladesSpecialCooldown < 5) || (atreusClasses[i].bow == 0) || (kratosClasses[i].heals == 0))
            {
                cout << "There is no moveset for " << selection << ", please input a valid selection." << endl;
                cin >> selection;
            };
            if (selection == 1)
            {
                int axeDamage = kratosClasses[i].leviathanAxeMinimum + (rand() % kratosClasses[i].leviathanAxeMaximum);
                draugerHealth -= axeDamage;
                cout << "Kratos hit's the Drauger with his axe and causes " << axeDamage << endl <<
                     " damage to its health." << endl;
            }
            else if (selection == 2)
            {
                axeSpecialCooldown = 0;
                int axeSpecial = kratosClasses[i].axeSpecialMinimum + (rand() % kratosClasses[i].axeSpecialMaximum);
                draugerHealth -= axeSpecial;
                cout << "Kratos uses his special axe attack and causes " << axeSpecial << endl <<
                     " damage to its health." << endl;
            }
            else if (selection == 3)
            {
                int bladeHits = kratosClasses[i].bladesSpeedMinimum + (rand() % kratosClasses[i].bladesSpeedMaximum);
                for (int j = bladeHits; j > 0; j--)
                {
                    int bladesDamage = kratosClasses[i].bladesOfChaosMinimum + (rand() % kratosClasses[i].bladesOfChaosMaximum);
                    draugerHealth -= bladesDamage;
                }
                cout << "Kratos hit the Drauger with the Blades of Chaos " << bladeHits << " times and got its " << endl <<
                     "health down to " << draugerHealth << endl;
            }
            else if (selection == 4)
            {
                bladesSpecialCooldown = 0;
                int bladeHits = kratosClasses[i].bladesSpecial;
                for (int j = bladeHits; j > 0; j--)
                {
                    int bladesDamage = kratosClasses[i].bladesOfChaosMinimum + (rand() % kratosClasses[i].bladesOfChaosMaximum);
                    draugerHealth -= bladesDamage;
                }
                cout << "Kratos hit the Drauger with the Blades of Chaos special attack" << bladeHits << " times and got its " << endl <<
                     "health down to " << draugerHealth << endl;
            }
            else if (selection == 6)
            {
                kratosClasses[i].kratosHealth = kratosClasses[i].kratosHealth + HEAL_STONE;
                kratosClasses[i].heals--;

                cout << "Kratos heals himself " << HEAL_STONE << " health bringing him up to " << kratosClasses[i].kratosHealth << endl;
            }
            else if (selection == 7)
            {
                draugerHealth -= atreusClasses[i].arrowDamage;
                atreusClasses[i].bow--;
                cout << "Kratos used Atreus to shoot an arrow at the drauger causing the drauger's health to go to " << draugerHealth << endl;
            }

            if (selection == 7)
            {
                cout << "Kratos used Atreus as a distraction and was able to avoid the attack" << endl;
            }
            else if (selection == 5)
            {
                int draugerDamage = draugerClasses[f].minimumAttack + (rand() % draugerClasses[f].maximumAttack);
                kratosClasses[i].kratosHealth = kratosClasses[i].kratosHealth - (draugerDamage * kratosClasses[i].shield);
                cout << "Kratos shielded himself, thus the Drauger getting him down to " << kratosClasses[i].kratosHealth << " health" << endl;
            }
            else
            {
                int draugerDamage = draugerClasses[f].minimumAttack + (rand() % draugerClasses[f].maximumAttack);
                kratosClasses[i].kratosHealth = kratosClasses[i].kratosHealth - draugerDamage;
                cout << "The Drauger did hit Kratos and got his health down to " << kratosClasses[i].kratosHealth << endl;
            }
            if (axeSpecialCooldown < 5)
            {
                axeSpecialCooldown += 1;
            }
            if (bladesSpecialCooldown < 5)
            {
                bladesSpecialCooldown += 1;
            }

            if (draugerHealth < 0)
            {
                draugerAmount -= 1;
                draugerCount += 1;
            }

            //Input Validation
            cin.clear();
        } while ((draugerHealth > 0) && (kratosClasses[i].kratosHealth > 0));

        //Input Validation
        cin.clear();
    } while ((draugerAmount > 0) && (kratosClasses[i].kratosHealth > 0));

    if (kratosClasses[i].kratosHealth <= 0)
    {
        deathMessage();
    }
    else
    {
        winnerMessage();
    }
}

void introductoryMessage()
{
    cout << "Welcome to God Of War, please select your class choice and press enter:" << endl;
    cout << "            1. Agility        2. Strength       3. Defense" << endl;
    cout << "Health      | 350             | 400             | 500" << endl;
    cout << "Axe Dmg.    | 20-30           | 30-40           | 10-20" << endl;
    cout << "Axe Range   | 15 Feet         | 30 Feet         | 20 Feet" << endl;
    cout << "Axe Hits    | 4               | 1               | 2" << endl;
    cout << "Axe Spec.   | 5-6 hits        | Instant Kill    | Double Hits" << endl;
    cout << "Blades Dmg. | 10-15           | 15-20           | 5-10" << endl;
    cout << "Blades Range| 5 feet          | 15 feet         | 10 feet" << endl;
    cout << "Blades Hits | 6-9             | 4-7             | 3-6" << endl;
    cout << "Blades Spec.| 13 Hit Combo    | Instant Kill    | 8 Hits" << endl;
    cout << "Deflection  | 25% Deflect     | 50% Deflect     | 75% Deflect" << endl;
    cout << "Heals       | 4 Moves         | 6 Moves         | 3 Moves" << endl;
    cout << "Atreus Bow  | 4               | 5               | 8" << endl;
    cout << "Arrow Dmg   | 10              | 10              | 10" << endl;
    cout << endl << "Specials are available in the beginning and reset every 5 moves or when enemy killed." << endl;
}

void mainStoryLine()
{
    cout << "Kratos and Atreus are on a journey to bring Faye, Kratos's wife's and Atreus's mother's," << endl <<
         "ashes to the highest peak in all the realms as per her wish, in the realm Jotunheim. " << endl <<
         "They go on a journey together as father and son. Throughout their journey, they go through " << endl <<
         "the realms of Midgard, Helheim, Nifelheim, Musphelheim, and Alfheim." << endl <<
         "They fight countless gods along the way, including Thor's sons, Magni and Modi, and Baldur, " << endl <<
         "facing off the 9 Vanir Valkyries one by one led by Sigrun.As they traversed " << endl <<
         "through the realms, battling each foe they face. They make it to the final leg of their journey, " << endl <<
         " and they are faced with one final task before their journey comes to an end." << endl <<
         "Their final lineup of enemys is the first they faced in the series, the Draugers, " <<  endl <<
         "as described in Atreus' codex, were warriors who dies, but their sould were too stubborn " << endl <<
         "and angry to stop fighting. These basic Drauger aren't very fast or strong. We can dodge or block them, " << endl <<
         " and take them down pretty easily." << endl << endl <<
         "Kratos's main weapons is his Leviathan Axe, handed down by his late wife, and the Blades of Chaos, " << endl <<
         "a blade with primoridial fire in it that he used to destroy the greek Pantheon." <<  endl <<
         "He also has the option of his son, Atreus, helping him by avoiding attacks but doing minimal damage" << endl;

    cout << endl << "Your final mission is to face the final wave of Drauger to " <<
         "take your mothers ashes to the highest peak in the realms" << endl << endl;
}

void deathMessage()
{
    cout << "The Drauger have ended your life, restart the code to try again" << endl;
}

void winnerMessage()
{
    cout << "As Kratos and Atreus chopped through the last of the Draugers" << endl <<
         ", the peak of the Jotunheim mountain was in their sights. On their way up, " << endl <<
         "they find prophecies about themselves on their journey and every encounter on the" << endl <<
         "journey, as Atreus goes to towards the peak of the mountain, Kratos sees a prophecy" << endl <<
         ", a phrophecy foretelling the future and showing dark future coming up ahead. " << endl <<
         "Since the two killed Baldur, it set Ragnarok, the end of Asgard and the Aesir gods, in motion. " << endl <<
         "Kratos, moving onto where Atreus is, they notice Faye was guiding their path the whole time." << endl <<
         "She was behind the whole prophecy, and knew what was coming, she had painted every available path" << endl <<
         ", every route, every area Kratos and Atreus visited, she knew, as the two, closer than ever, " << endl <<
         "father and son, climb together to the top and spread Faye's ashes at the highest peak in all " << endl <<
         "of the 9 realms, as they make their way back home, they go straight to bed after the long journey" << endl;

}