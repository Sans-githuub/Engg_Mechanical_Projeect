
//______________________________________________________Required Preprocessros______________________________________________________

#include <stdio.h>
#include <math.h>
#include <systemtopologyapi.h>
#define Degree_to_Radian 0.0174532925;

// ___________________________________________________Declaring Global variables____________________________________________________

float x, y, Angle_Theta_in_Degree, Angle_in_Radian, Sin_Angle, Cos_Angle, Sin_cal, Cos_cal;
float a, b, Alpha_Angle_in_Degree, Hydraulic_Angle, Hydraulic_Angle_Radian, Hydraulic_Sin_Angle, Hydraulic_Cos_Angle;
float Mass_of_Load, Weight_of_Load, Load_Force, Boom_Force;
float Boom_Length, COG_Length, Hydraulic_Length, Hydraulic_Axis_Length, BL, COG_L, HL, HAL, Feet_to_Meter;
float Hydraulic_Reaction_Force, Vertical_Load_Force, Vertical_Cog_Force, Hydraulic_Force, Hydraulic_Axis_Force;
float Resultant_Force, Force, Resultant_Ans;
float xcomp, x_Comp, Force_x, ycomp, y_Comp, Force_y;
float X_Component_Force, y_Component_Force, Resultant_Crane_Force, Crane_Resultant, Crane_Resultant_Force;
float array[10], arr[10], arra[10];
int case_num, counter, condition;
char name[50];

//______________________________________________________Declation of function_______________________________________________________

float Angle_Input(float);
float Angle_Calculation(float *Angle_Cal);
float Distance_Calulation(float);
float Reaction_Force(float);
float xComponent_Force(float);
float yComponent_Force(float);
float Resultant(float);

//__________________________________________________________Main Section___________________________________________________________

float main(void)
{
    system("color 3");
    printf("\n\n\n---------------------------------------------Enter your name to proceed.------------------------------------------------\n\n\n==> ");
    scanf("%s", &name);
top:
    printf("\n\n_________________________________________Hello,%s welcome to my C-Program____________________________________________\n\n", name);
    printf("\n\nThis Program includes Three Diffrent Cases:\nPlease,Enter:\n\n=> 1 : For CaseI   (This Case Includes the Calculation of Resultant Force on Hydraulic Cylinder of Boom of the Crane.)\n=> 2 : For CaseII  (This Case Includes the Calculation of Resultant Force on the Pivot of Boom of the Crane.)\n=> 3 : For CaseIII (This Case Compares the Resultant Force on Hydraulic Cylinder by giving Different Inputs.)\n\n The Case you Choose is: ");
    scanf("%d", &case_num);

    // -------------------------------------------------------Switch Case Starts------------------------------------------------------

    switch (case_num)
    {
    case 1:
        // ________________________________________For Angle of Boom of the crane i.e"Θ"______________________________________________

    First:
        printf("\n\nEnter the Angle of Boom in Degree : ");
        scanf("%f", &Angle_Theta_in_Degree);
        Angle_Input(Angle_Theta_in_Degree);
        Sin_Angle = Angle_in_Radian;
        x = Angle_Calculation(&Sin_Angle);
        Cos_Angle = Angle_in_Radian;
        y = Angle_Calculation(&Cos_Angle);

        //___________________________For Angle of Hydraulic Cylinder and the Boom of the crane i.e(90-Θ-α)__________________________

        printf("\n\nEnter the Alpha Angle in Degree : ");
        scanf("%f", &Alpha_Angle_in_Degree);
        Hydraulic_Angle = 90 - Angle_Theta_in_Degree - Alpha_Angle_in_Degree;
        Angle_Input(Hydraulic_Angle);
        Hydraulic_Sin_Angle = Angle_in_Radian;
        a = Angle_Calculation(&Hydraulic_Sin_Angle);
        Hydraulic_Cos_Angle = Angle_in_Radian;
        b = Angle_Calculation(&Hydraulic_Cos_Angle);

        //_____________________________________________________Force Input__________________________________________________________

        printf("\n\nEnter the Mass of the Load to be Lifted by the crane : ");
        scanf("%f", &Mass_of_Load);

        Weight_of_Load = Mass_of_Load * 10;
        Load_Force = Weight_of_Load;

        printf("\n\nEnter the Force By the COF of the Boom : ");
        scanf("%f", &Boom_Force);

        //___________________________________________________Input Distance________________________________________________________

        printf("\n\nEnter The Length of Boom in Feet : ");
        scanf("%f", &Boom_Length);
        BL = Distance_Calulation(Boom_Length);

        printf("\n\nEnter The distance of COG in Feet : ");
        scanf("%f", &COG_Length);
        COG_L = Distance_Calulation(COG_Length);

        printf("\n\nEnter The distance of Hydraulic Cylinder from the Pivot in Feet : ");
        scanf("%f", &Hydraulic_Length);
        HL = Distance_Calulation(Hydraulic_Length);

        printf("\n\nEnter The distance of Hydraulic Cylinder from the axis of Boom in Feet : ");
        scanf("%f", &Hydraulic_Axis_Length);
        HAL = Distance_Calulation(Hydraulic_Axis_Length);

        // <===========================================Calculation of Case-I ===================================================>

        float Result = Reaction_Force(Force);

        printf("\n\nThe Datas that You have Entered are:\n\n");
        printf("\t\t\t----------------------------------------------------------------------\n");
        printf("\t\t\t\t--------------------------------------------------------");
        printf("\n\t\t\t\t| Angle Between Boom of Crane and Horizontal  |  %.2f", Angle_Theta_in_Degree);
        printf("\n\t\t\t\t| Angle Betwn Hydraulic Cylinder & Vertical   |  %.2f", Alpha_Angle_in_Degree);
        printf("\n\t\t\t\t| Weight that is Given to Crane to lifts      |  %.0fN", Weight_of_Load);
        printf("\n\t\t\t\t| Force of Centrer of Gravity of the Boom     |  %.0fN", Boom_Force);
        printf("\n\t\t\t\t| The Distance of Boom From the pivot in Feet |  %.2f", Boom_Length);
        printf("\n\t\t\t\t| The Distance of COG From the pivot in Feet  |  %.2f", COG_Length);
        printf("\n\t\t\t\t| The Distance of Hydraulic Cylinder in Feet  |  %.2f", Hydraulic_Length);
        printf("\n\t\t\t\t| The Distance From Axis to Surface of Boom   |  %.2f", Hydraulic_Axis_Length);
        printf("\n\t\t\t\t-------------------------------------------------------\n");
        printf("\t\t\t----------------------------------------------------------------------");

        printf("\n\n\nThefore, Considering All the Given Datas, Resultant Force of the Hydraulic Cylinder is : %.10f\n\n", Result);

        if (case_num == 2)
        {
            goto Second;
        }
        break;

    case 2:

        goto First;
    Second:
        //<=============================================Calcultion of Case-II===================================================>

        Force_x = (xComponent_Force(x_Comp));
        printf("\n\nThe X component of Resultant Force is: %.10f", Force_x);
        if (Force_x < 0)
        {
            printf("\n\nThe negative sign indicates that the direction we assumed was wrong.");
        }

        Force_y = (yComponent_Force(y_Comp));
        printf("\n\nThe Y component of Resultant Force is: %.10f", Force_y);
        if (Force_y < 0)
        {
            printf("\n\nThe negative sign indicates that the direction we assumed was wrong.");
        }

        Crane_Resultant_Force = Resultant(Resultant_Crane_Force);
        printf("\n\nTherefore, the Final Resultant Force of the Crane is: %.10f\n\n", Crane_Resultant_Force);

        break;

    case 3:

        printf("\n\nEnter the Number of Different Entries you would like to give: ");
        scanf("%d", &counter);
        for (int i = 1; i <= counter; i++)
        {
            printf("\n\n\n________________________________________________________Data No.%d________________________________________________________\n\n", i);
            printf("\n\nEnter the Angle of Boom in Degree:");
            scanf("%f", &Angle_Theta_in_Degree);
            Angle_Input(Angle_Theta_in_Degree);
            Sin_Angle = Angle_in_Radian;
            x = Angle_Calculation(&Sin_Angle);
            Cos_Angle = Angle_in_Radian;
            y = Angle_Calculation(&Cos_Angle);

            //_________________________________For Angle of Hydraulic Cylinder with Vertical i.e"α"__________________________________

            printf("\n\nEnter the Alpha Angle in Degree:");
            scanf("%f", &Alpha_Angle_in_Degree);

            //_________________________For Angle of Hydraulic Cylinder and the Boom of the crane i.e(90-Θ-α)________________________

            Hydraulic_Angle = 90 - Angle_Theta_in_Degree - Alpha_Angle_in_Degree;
            Angle_Input(Hydraulic_Angle);
            Hydraulic_Sin_Angle = Angle_in_Radian;
            a = Angle_Calculation(&Hydraulic_Sin_Angle);
            Hydraulic_Cos_Angle = Angle_in_Radian;
            b = Angle_Calculation(&Hydraulic_Cos_Angle);

            //____________________________________________________Input Force_______________________________________________________

            printf("\n\nEnter the Mass of the Load to be Lifted by the crane:");
            scanf("%f", &Mass_of_Load);

            Weight_of_Load = Mass_of_Load * 10;
            Load_Force = Weight_of_Load;

            printf("\n\nEnter the Force By the COF of the Boom:");
            scanf("%f", &Boom_Force);

            // _________________________________________________Input Distance_____________________________________________________

            printf("\n\nEnter The Length of Boom in Feet: ");
            scanf("%f", &Boom_Length);
            BL = Distance_Calulation(Boom_Length);

            printf("\n\nEnter The distance of COG in Feet:");
            scanf("%f", &COG_Length);
            COG_L = Distance_Calulation(COG_Length);

            printf("\n\nEnter The distance of Hydraulic Cylinder from the Pivot in Feet:");
            scanf("%f", &Hydraulic_Length);
            HL = Distance_Calulation(Hydraulic_Length);

            printf("\n\nEnter The distance of Hydraulic Cylinder from the axis of Boom in Feet:");
            scanf("%f", &Hydraulic_Axis_Length);
            HAL = Distance_Calulation(Hydraulic_Axis_Length);

            // <========================================Calculation of CaseIII==================================================>

            array[i] = Reaction_Force(Force);
            arr[i] = Angle_Theta_in_Degree;
            arra[i] = Alpha_Angle_in_Degree;

            printf("\n\nThe Datas that You have Entered are:\n\n");
            printf("\t\t\t----------------------------------------------------------------------\n");
            printf("\t\t\t\t--------------------------------------------------------");
            printf("\n\t\t\t\t| Angle Between Boom of Crane and Horizontal  |  %.2f", Angle_Theta_in_Degree);
            printf("\n\t\t\t\t| Angle Betwn Hydraulic Cylinder & Vertical   |  %.2f", Alpha_Angle_in_Degree);
            printf("\n\t\t\t\t| Weight that is Given to Crane to lifts      |  %.0fN", Weight_of_Load);
            printf("\n\t\t\t\t| Force of Centrer of Gravity of the Boom     |  %.0fN", Boom_Force);
            printf("\n\t\t\t\t| The Distance of Boom From the pivot in Feet |  %.2f", Boom_Length);
            printf("\n\t\t\t\t| The Distance of COG From the pivot in Feet  |  %.2f", COG_Length);
            printf("\n\t\t\t\t| The Distance of Hydraulic Cylinder in Feet  |  %.2f", Hydraulic_Length);
            printf("\n\t\t\t\t| The Distance From Axis to Surface of Boom   |  %.2f", Hydraulic_Axis_Length);
            printf("\n\t\t\t\t-------------------------------------------------------\n");
            printf("\t\t\t----------------------------------------------------------------------");
        }
        for (int i = 1; i <= counter; i++)
        {
            printf("\n\nThe Resultant Force of Data.no%d is %.10f for the Given Input.\n\n", i, array[i], arr[i], arra[i]);
        }
        break;

    default:
    here:
        printf("\n\n=============================================Your Given Input is wrong===================================================");
        printf("\n\n___________________________________________Do you want to try again????_________________________________________________");
        printf("\n=> 1 : Try Again\n=> 0 : End the Program\n\n");
        scanf("%d", &condition);

        switch (condition)
        {
        case 1:
            goto top;
            break;
        case 0:
            printf("\n\n\t\t\t\t\t\t End of the Program\n\n\n\n");
            break;

        default:
            goto here;
            break;
        }
        break;
    }
}

//-----------------------------------------------------------Defining funcitons--------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------Function for Input of Angles---------------------------------------------------

float Angle_Input(float Angle)
{
    Angle_in_Radian = Angle * Degree_to_Radian;
    return Angle_in_Radian;
}

//--------------------------------------------------Function for Calculation of Angles-------------------------------------------------

float Angle_Calculation(float *Angle_Cal)
{
    if (Angle_Cal == &Sin_Angle || Angle_Cal == &Hydraulic_Sin_Angle)
    {
        float Sin_cal = sin(*Angle_Cal);
        return Sin_cal;
    }
    else
    {
        float Cos_cal = cos(*Angle_Cal);
        return Cos_cal;
    }
}

//-------------------------------------------Function for Converting given distance in meter------------------------------------------

float Distance_Calulation(float Distance)
{
    Feet_to_Meter = 0.3048 * Distance;
    return Feet_to_Meter;
}

// -----------------------------------------------------First case Calculation--------------------------------------------------------

float Reaction_Force(float Resultant_Force)
{
    Vertical_Load_Force = Load_Force * BL * y;
    Vertical_Cog_Force = Boom_Force * COG_L * y;
    Hydraulic_Force = HL * a;
    Hydraulic_Axis_Force = HAL * b;

    Resultant_Force = (Vertical_Cog_Force + Vertical_Load_Force) / (Hydraulic_Force + Hydraulic_Axis_Force);
    Resultant_Ans = Resultant_Force;
    return Resultant_Ans;
}

//-------------------------------------------function for finding Xcomponent of the force---------------------------------------------

float xComponent_Force(float xcomp)
{
    xcomp = Boom_Force * x + Load_Force * x - Resultant_Ans * b;
    X_Component_Force = xcomp;
    return xcomp;
}

// ------------------------------------------function for finding Ycomponent of the force---------------------------------------------

float yComponent_Force(float ycomp)
{
    ycomp = Boom_Force * y + Load_Force * y - Resultant_Ans * a;
    y_Component_Force = ycomp;
    return ycomp;
}

//-------------------------------------------function for finding Resultant of the force---------------------------------------------

float Resultant(float Resultant_Crane_Force)
{
    Resultant_Crane_Force = sqrt(pow(X_Component_Force, 2) + pow(y_Component_Force, 2));
    Crane_Resultant = Resultant_Crane_Force;
    return Crane_Resultant;
}
