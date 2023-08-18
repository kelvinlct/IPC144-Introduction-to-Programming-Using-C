#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    if (patient[0].patientNumber == 0) {
        printf("***No records found ***");
    }
    else {
        displayPatientTableHeader();
        int i;
        for (i = 0; i < max; i++) {
            if (patient[i].patientNumber != 0) {
                displayPatientData(&patient[i], fmt);
            }
        }
        printf("\n");
    }
};

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max) {

    int selection;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        printf("\n");
        if (selection == 1) {
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (selection == 2) {
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }
    } while (selection);
};


// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int i, j = 0;
    int empty = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == 0) {
            empty = 1;
        }
    }
 //   if (patient[max - 1].patientNumber != 0) {
    if (empty == 0) {
        printf("ERROR: Patient listing is FULL!\n");
    }
    else {
        for (i = 0; (i < max) && j == 0; i++) {
            if (patient[i].patientNumber == 0) {
                patient[i].patientNumber = nextPatientNumber(patient, max);
                inputPatient(&patient[i]);
                j = 1;
                printf("*** New patient record added ***\n");
            }
        }
    }
    printf("\n");
};

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
    int patNum, patIndex;
    printf("Enter the patient number: ");
    patNum = inputIntPositive();
    patIndex = findPatientIndexByPatientNum(patNum, patient, max);
    printf("\n");
    if (patIndex == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        menuPatientEdit(&patient[patIndex]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int patNum, patIndex;
    //int i ,j;
    char yn;
    char check[3] = { 'y','n','\0'};
    //struct Patient temp;
    printf("Enter the patient number: ");
    patNum = inputIntPositive();
    patIndex = findPatientIndexByPatientNum(patNum, patient, max);
    printf("\n");
    if (patIndex == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        displayPatientData(&patient[patIndex], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        yn = inputCharOption(check);
        if (yn == 'y') {
            patient[patIndex].patientNumber = 0;
            patient[patIndex].patientNumber = 0;
            patient[patIndex].name[0] = '\0';
            patient[patIndex].phone.description[0] = '\0';
            patient[patIndex].phone.number[0] = '\0';

            //for (i = max -1 ; i > 0; i--) {
            //    for (j = 0; j < i; j++) {
            //        if (patient[j].patientnumber > patient[j + 1].patientnumber && patient[j + 1].patientnumber != 0) {
            //            temp = patient[j];
            //            patient[j] = patient[j + 1];
            //            patient[j + 1] = temp;
            //        }


            //    }
            //}

            //for (i = 0; i < max; i++) {
                //if (patient[i].patientNumber == 99999) {
                //    patient[i].patientNumber = 0;
                //    patient[i].name[0] = '\0';
                //    patient[i].phone.description[0] = '\0';
                //    patient[i].phone.number[0] = '\0';
                //}

            //}

            printf("Patient record has been removed!\n");
        }
        else {
            printf("Operation aborted.\n");
        }
        printf("\n");
    }
    
};

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data) {
    displayScheduleTableHeader(NULL, 1);
    int i = 0, j = 0;
    Sorting(data->appointments);

    for (j = 0; j < data->maxAppointments; j++) {
        for (i = 0; i < data->maxPatient; i++) {
            if ((data->patients[i].patientNumber == data->appointments[j].patNum)&& (data->appointments[j].patNum !=0)) {
                displayScheduleData(&data->patients[i], &data->appointments[j], 1);
            }
        }

    }
    printf("\n");
};

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    int i, j;
    struct Appointment apt;

    inputDateTime(&apt, NOTIME);

    Sorting(data->appointments);
    printf("\n");
    displayScheduleTableHeader(&apt.date, 0);

    for (i = 0; i < data->maxAppointments; i++) {
        if ((data->appointments[i].date.year == apt.date.year) && (data->appointments[i].date.month == apt.date.month) && (data->appointments[i].date.day == apt.date.day)) {
            for (j = 0; j < data->maxAppointments; j++) {
                if ((data->patients[j].patientNumber == data->appointments[i].patNum) && (data->appointments[i].patNum != 0)) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }

        }
    }
    printf("\n");
};

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patient, int maxPatient) {
    int i, k, keepLoop;
    struct Appointment apt;

    for (k = 0; appointments[k].date.year != 0; k++) {
        ;
    }

    printf("Patient Number: ");
    apt.patNum = inputIntPositive();
    do {
        keepLoop = 0;
        inputDateTime(&apt, INCLUDETIME);
        for (i = 0; i < maxPatient; i++) {
            if (apt.date.month == appointments[i].date.month && apt.date.year == appointments[i].date.year && apt.time.hour == appointments[i].time.hour && apt.time.min == appointments[i].time.min) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
                keepLoop = 1;
            }
        }
    } while (keepLoop);
    
    appointments[k] = apt;

    printf("\n*** Appointment scheduled! ***\n\n");
};


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patient, int maxPatient) {
    int i, j, found = 0;
    char yn;
    char check[3] = { 'y','n','\0' };
    struct Appointment apt;


    printf("Patient Number: ");
    apt.patNum = inputIntPositive();
    for (i = 0; i < maxAppointments; i++) {
        if (apt.patNum == appointments[i].patNum) {
            found = 1;
        }
    }
    if (found == 1) {
        inputDateTime(&apt, NOTIME);
        printf("\n");
    
            for (i = 0; i < maxAppointments; i++) {

                if (apt.patNum == appointments[i].patNum && apt.date.day == appointments[i].date.day && apt.date.month == appointments[i].date.month && apt.date.year == appointments[i].date.year) {
                    j = findPatientIndexByPatientNum(apt.patNum, patient, maxPatient);
                    displayPatientData(&patient[j], FMT_FORM);
                    printf("Are you sure you want to remove this appointment (y,n): ");
                    yn = inputCharOption(check);
                    if (yn == 'y') {
                        appointments[i].date.year = REMOVE;
                        Sorting(appointments);                        
                    }
                    RemoveArrayElement(appointments, maxAppointments);
                    printf("\nAppointment record has been removed!\n\n");

                }
            
            }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
    }
};

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    printf("Search by patient number: ");
    int input = inputIntPositive();
    printf("\n");
    int i, j = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == input) {
            displayPatientData(&patient[i], FMT_FORM);
            j = 1;
        }
    }
    if (j == 0) {
        printf("*** No records found ***\n");
    }
    printf("\n");
};

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    printf("Search by phone number: ");
    char input[PHONE_LEN + 1];
    inputCString(input, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    int i, j = 0;
    for (i = 0; i < max; i++) {
        int result = strcmp(patient[i].phone.number, input);
        if (result == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            j = 1;
        }
    }
    if (j == 0) {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
};

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) {
    int patientNum, i, maxNum = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNum) {
            maxNum = patient[i].patientNumber;
        }
    }
    patientNum = maxNum + 1;
    return patientNum;
};

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i, j = -1;
    for (i = 0; i < max; i++) {
        if (patientNumber == patient[i].patientNumber) {
            j = i;
        }
    }
    return j;
};


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");

    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
};

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) {
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    switch (selection) {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }
    printf("\n");
    if (selection != 4) {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        printf("\n");
    }
};



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    int patientsCount = 0;

    FILE* fp = fopen(datafile,"r"); 

    if (fp != NULL) {

        for (patientsCount = 0; patientsCount < max; patientsCount++) {
            if (feof(fp) != 1) {
                fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[patientsCount].patientNumber, patients[patientsCount].name, patients[patientsCount].phone.description, patients[patientsCount].phone.number);
            }
        }

        fclose(fp);
        fp = NULL;

    }
    else {
        printf("Fail to read file\n");
    }
    return patientsCount;
};

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    int appointmentsCount = 0;
    char ch;

    FILE* fp = fopen(datafile, "r"); 
    if (fp != NULL) {
        
        while (appointmentsCount < max && fscanf(fp, "%d,%d,%d,%d,%d,%d%c", &appoints[appointmentsCount].patNum, &appoints[appointmentsCount].date.year, &appoints[appointmentsCount].date.month, &appoints[appointmentsCount].date.day, &appoints[appointmentsCount].time.hour, &appoints[appointmentsCount].time.min, &ch) == 7) {
            if (ch != '\n') {
                while (fgetc(fp) != '\n');
            }
            appointmentsCount++;
        }
        
        fclose(fp);
        fp = NULL;

    }
    else {
        printf("Fail to read file\n");
    }
    return appointmentsCount;
};

//Sorting
void Sorting(struct Appointment* appointments) {
    int i = 0, j = 0, k;
    int timeA, timeB;
    struct Appointment temp;

    for (k = 0; appointments[k].date.year != 0; k++) {
        ;
    }

    for (i = k; i > 0; i--) {
        for (j = 0; j < i; j++) {
            timeA = (appointments[j].time.min + appointments[j].time.hour * 60 + appointments[j].date.day * 1440 + appointments[j].date.month * 44640 + appointments[j].date.year * 535680);
            timeB = (appointments[j + 1].time.min + appointments[j + 1].time.hour * 60 + appointments[j + 1].date.day * 1440 + appointments[j + 1].date.month * 44640 + appointments[j + 1].date.year * 535680);

            if (timeA > timeB) {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}



void inputDateTime(struct Appointment* apt, int includeTime) {
    int y, m, d, hour, min, i = 1;
    printf("Year        : ");
    y = inputIntPositive();

    printf("Month (1-12): ");
    m = inputIntRange(1, 12);

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        printf("Day (1-31)  : ");
        d = inputIntRange(1, 31);
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        printf("Day (1-30)  : ");
        d = inputIntRange(1, 30);
    }
    else {
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {

            printf("Day (1-29)  : ");
            d = inputIntRange(1, 29);
        }
        else {
            printf("Day (1-28)  : ");
            d = inputIntRange(1, 28);
        }

    }
    apt->date.day = d;
    apt->date.month = m;
    apt->date.year = y;

    if (includeTime == 1) {
        do {
            printf("Hour (0-23)  : ");
            hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            min = inputIntRange(0, 59);
            if (hour < OPEN || (hour*100+min) > (CLOSE*100) || min % INTERVAL != 0) {
                printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", OPEN, CLOSE, INTERVAL);
            }
            else {
                i = 0;
            }
        } while (i);
        apt->time.hour = hour;
        apt->time.min = min;
    }
}

//Remove array element
void RemoveArrayElement(struct Appointment* appointments, int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (appointments[i].date.year == REMOVE) {
            appointments[i].patNum = 0;
            appointments[i].date.day = 0;
            appointments[i].date.month = 0;
            appointments[i].date.year = 0;
            appointments[i].time.hour = 0;
            appointments[i].time.min = 0;
        }
    }
}