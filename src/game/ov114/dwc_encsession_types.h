#ifndef OV114_DWC_ENCSESSION_TYPES_H
#define OV114_DWC_ENCSESSION_TYPES_H
/* Encrypted GameSpy session state (dwc_encsession.o) shared by the two halves of the module. */

#ifndef OV114_BASIC_TYPES
#define OV114_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

typedef int (*DWCEncResponseCallback)(unsigned int *response, int responseLen);

typedef struct DWCEncSession {
    int state;
    int isInitialized;
    int requestId;
    int isKeyValid;
    char gameName[32];
    char secretKey[20];
    unsigned int randMultiplier;
    unsigned int randIncrement;
    unsigned int randModulus;
    unsigned int checksumMask;
    char *request;
    char *hashPosition;
    char *payload;
    void *responseBuffer;
    unsigned int responseBufferLen;
    void *decodedBuffer;
    unsigned int decodedBufferLen;
    DWCEncResponseCallback callback;
    char lastHash[41];
} DWCEncSession;

extern DWCEncSession gDwcEncSession;
extern int gDwcEncRandState;

#endif
