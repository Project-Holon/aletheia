/*
 * function: sciWsSubmitReportCallback
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
 *   gsXmlMoveToStart  0x021834D0  arm  ov009
 *   gsXmlMoveToNext  0x021834E8  arm  ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm  ov009
 *   sSciTagSubmitReportResponse  0x021E43D4  data
 *   sSciTagSubmitReportResult  0x021E43EC  data
 *   sSciTagResult  0x021E42BC  data
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

extern int gsXmlMoveToStart(int *p);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern char sSciTagSubmitReportResponse[];
extern char sSciTagSubmitReportResult[];
extern char sSciTagResult[];

void sciWsSubmitReportCallback(int theHttpResult, int unused, void *theResponseData, struct SCIRequest *theUserData)
{
    int submitResult;
    int aTranslatedResult;

    if (theUserData->active == 0)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = 0;
        submitResult = 0;
        if (!gsXmlMoveToStart(theResponseData)
            || !gsXmlMoveToNext(theResponseData, sSciTagSubmitReportResponse)
            || !gsXmlMoveToNext(theResponseData, sSciTagSubmitReportResult)
            || !gsXmlReadChildAsInt(theResponseData, sSciTagResult, &submitResult)) {
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
