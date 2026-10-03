/*
 * function: func_021E0FE8
 * address:  0x021E0FE8
 * packet:   pkt_ov175_021E0FE8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciWsSubmitReportCallback (libdwcgssc.TWL.HYB.a(sciwebservices.o))
 *
 * symbols:
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_02183A24  0x02183A24  arm  ov009
 *   g_021E43D4  0x021E43D4  data
 *   g_021E43EC  0x021E43EC  data
 *   g_021E42BC  0x021E42BC  data
 */

struct SCIRequest {
    void *ws;
    char pad0[0xc - 4];
    void (*callback)(void *, int, int, void *);
    char pad1[0x18 - 0x10];
    int f18;
    char pad2[0x30 - 0x1c];
    void *userData;
    char pad3[0x48 - 0x34];
    int active;
};

extern int func_021834D0(int *p);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_02183A24(void *stream, char *matchtag, int *valueOut);
extern char g_021E43D4[];
extern char g_021E43EC[];
extern char g_021E42BC[];

void func_021E0FE8(int theHttpResult, int unused, void *theResponseData, struct SCIRequest *theUserData)
{
    int submitResult;
    int aTranslatedResult;

    if (theUserData->active == 0)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = 0;
        submitResult = 0;
        if (!func_021834D0(theResponseData)
            || !func_021834E8(theResponseData, g_021E43D4)
            || !func_021834E8(theResponseData, g_021E43EC)
            || !func_02183A24(theResponseData, g_021E42BC, &submitResult)) {
            aTranslatedResult = 9;
        } else if (submitResult != 0) {
            if (submitResult == 7)
                aTranslatedResult = 12;
            else
                aTranslatedResult = 8;
        }
    } else {
        aTranslatedResult = 7;
    }
    theUserData->f18 = 0;
    if (theUserData->callback != 0) {
        theUserData->callback(theUserData->ws, theHttpResult, aTranslatedResult, theUserData->userData);
        theUserData->userData = 0;
        theUserData->callback = 0;
    }
}
