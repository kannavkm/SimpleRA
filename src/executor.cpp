#include"global.h"

void executeCommand() {

    switch (parsedQuery->queryType) {
        case CLEAR:
            executeCLEAR();
            break;
        case CROSS:
            executeCROSS();
            break;
        case DISTINCT:
            executeDISTINCT();
            break;
        case EXPORT:
            executeEXPORT();
            break;
        case EXPORTMATRIX:
            executeEXPORTMATRIX();
            break;
        case GROUPBY:
            executeGROUPBY();
        case INDEX:
            executeINDEX();
            break;
        case JOIN:
            executeJOIN();
            break;
        case LIST:
            executeLIST();
            break;
        case LISTMATRIX:
            executeLISTMATRIX();
            break;
        case LOAD:
            executeLOAD();
            break;
        case LOADMATRIX:
            executeLOADMATRIX();
            break;
        case PRINT:
            executePRINT();
            break;
        case PRINTMATRIX:
            executePRINTMATRIX();
            break;
        case PROJECTION:
            executePROJECTION();
            break;
        case RENAME:
            executeRENAME();
            break;
        case SELECTION:
            executeSELECTION();
            break;
        case SORT:
            executeSORT();
            break;
        case SOURCE:
            executeSOURCE();
            break;
        case TRANSPOSE:
            executeTRANSPOSE();
            break;
        default:
            cout << "PARSING ERROR" << endl;
    }

}
