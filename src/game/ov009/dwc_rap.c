/*
 * file:     dwc_rap.c
 * unit:     yes
 * function: func_02155160, func_02155168, func_021551B0, func_021551DC, func_02155204, func_02155234, func_0215523C, func_02155244, func_02155264, func_02155280, func_0215528C, func_02155294, func_021552AC, func_021552DC, func_021552E8, func_02155330, func_02155338, func_0215536C, func_02155374, func_02155388, func_0215539C, func_021554A0, func_021554C8, func_02155648, func_02155664, func_02155674, func_02155678, func_0215568C, func_0215580C, func_02155904, func_0215592C, func_02155A80, func_02155B00, func_02155B14, func_02155B68, func_02155B98, func_02155BDC, func_02155C0C, func_02155C24, func_02155C28, func_02155C6C, func_02155C70, func_02155C8C, func_02155D2C, func_02155D3C, func_02155D7C, func_02155D80, func_02155DA4, func_02155DCC, func_02155E9C, func_02155F58, func_0215610C, func_0215615C, func_021561C0, func_021562EC, func_02156330, func_02156344, func_021563C0, func_021563D0, func_021563EC, func_02156400, func_0215642C, func_02156460, func_02156690, func_02156730, func_0215677C, func_021567B8, func_0215683C, func_02156860, func_02156874, func_02156888, func_02156A3C, func_02156A58, func_02156B18, func_02156B3C, func_02156B68, func_02156B70, func_02156B8C, func_02156BA8, func_02156BC4, func_02156BD8, func_02156C00, func_02156C60, func_02156C84, func_02156C98, func_02156CAC, func_02156CD0, func_02156CF4, func_02156D84, func_02156DC4, func_02156DE0, func_02156DFC, func_02156E24, func_02156E30, func_02156ED0, func_02156F14, func_02156F50, func_02156F5C, func_02156FDC, func_02157048, func_021570B8, func_02157108, func_02157138, func_02157160, func_02157170
 * address:  0x02155160
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_02030734  0x02030734  arm
 *   _pSetupParam     0x021A8260  data  ov009  a4
 *   _sNetDevwifiFile     0x021A1C4C  data  ov009  a1
 *   func_0203D5EC 0x0203D5EC arm
 *   func_0203D610 0x0203D610 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0216B908 0x0216B908 arm ov009
 *   func_0205CCD8  0x0205CCD8  arm
 *   func_02059E38  0x02059E38  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203CA98  0x0203CA98  arm
 *   _wifiDeviceTable  0x021A1B80  data
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   _sAssertEmpty     0x021A1C5C  data  ov009  a1
 *   _sDwcRapFile     0x021A1C60  data  ov009  a1
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_02034714  0x02034714  arm
 *   func_020597C8  0x020597C8  arm
 *   func_02059760  0x02059760  arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02059F18 0x02059F18 arm
 *   _pRapWorkAddr 0x021A8264  data  ov009  a4
 *   _sGameName     0x021A1C6C  data  ov009  a1
 *   func_0205C6AC  0x0205C6AC  arm
 *   func_0205C758  0x0205C758  arm
 *   func_0205C88C  0x0205C88C  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0205C8E0  0x0205C8E0  arm
 *   func_0216AB20  0x0216AB20  arm
 *   func_02087C88  0x02087C88  arm
 *   func_0216B0E0  0x0216B0E0  arm
 *   func_0216AE88  0x0216AE88  arm
 *   func_0216B1E0  0x0216B1E0  arm
 *   func_02168994  0x02168994  arm
 *   _sMatchKey     0x021A1C74  data  ov009  a1
 *   _sMatchFilterFormat     0x021A1974  data  ov009  a1
 *   func_0216CA04  0x0216CA04  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02094530  0x02094530  arm
 *   func_0203F004  0x0203F004  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0216B284  0x0216B284  arm
 *   func_02177138  0x02177138  arm
 *   func_02177160  0x02177160  arm
 *   func_0216B634  0x0216B634  arm
 *   func_02177188  0x02177188  arm
 *   func_0216B65C  0x0216B65C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02176FD4  0x02176FD4  arm
 *   func_0216B838  0x0216B838  arm
 *   func_0205984C  0x0205984C  arm
 *   func_02059870  0x02059870  arm
 *   func_02177270  0x02177270  arm
 *   func_021AEF44  0x021AEF44  thumb  ov013
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0216B804  0x0216B804  arm  ov009
 *   func_0203A338  0x0203A338  arm
 *   func_0205CC20  0x0205CC20  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_0216AD50  0x0216AD50  arm  ov009
 *   func_021C5B80  0x021C5B80  arm  ov114
 *   DWC_GdbShutdown  0x021E1340  arm
 *   func_0216B94C  0x0216B94C  arm  ov009
 *   func_02176DEC  0x02176DEC  arm  ov009
 *   func_021AEE14  0x021AEE14  thumb  ov013
 *   func_021AF238  0x021AF238  thumb  ov013
 *   func_021AEF6C  0x021AEF6C  thumb  ov013
 *   func_021AF18C  0x021AF18C  thumb  ov013
 *   func_021AF13C  0x021AF13C  thumb  ov013
 *   func_021AF1A0 0x021AF1A0 thumb ov013
 *   func_021AF2AC 0x021AF2AC thumb ov013
 *   func_021AF30C 0x021AF30C thumb ov013
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0205912C  0x0205912C  arm
 *   func_02168848  0x02168848  arm  ov009
 *   func_021688FC 0x021688FC arm ov009
 *   func_0216B354  0x0216B354  arm  ov009
 *   func_0216B408  0x0216B408  arm  ov009
 *   func_0216B7E0  0x0216B7E0  arm  ov009
 *   func_021AF210 0x021AF210 thumb ov013
 *   func_021770EC  0x021770EC  arm  ov009
 *   abs_id_11  0x00000011  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021B6100  0x021B6100  thumb  ov017
 *   _pRapHeap  0x021A8268  data  ov009  a4
 *   _sAssertEmptyCommon  0x021A1C78  data  ov009  a1
 *   _sDwcRapCommonFile  0x021A1C7C  data  ov009  a1
 *   func_02060C5C  0x02060C5C  arm
 *   func_02060F18  0x02060F18  arm
 *   func_02060F40  0x02060F40  arm
 *   func_02060C94  0x02060C94  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02060CA0  0x02060CA0  arm
 *   func_0200FB6C  0x0200FB6C  thumb
 *   func_02060F98  0x02060F98  arm  arm9
 *   func_02060E30  0x02060E30  arm
 *   _sDwcGameName  0x021A1C8C  data  ov009  a1
 *   func_02059F6C  0x02059F6C  arm
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   func_02059718       0x02059718  arm
 *   DWC_CreateUserData  0x020596FC  arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0203C554  0x0203C554  arm
 */
#include "dwc_rap_types.h"

struct DWCstAccUserData;
struct OSOwnerInfo;
struct ExpHeap;
typedef signed short   s16;

typedef void (*VoidFunc)(void);

typedef struct {
    u8 language, favoriteColor, month, day;
    u16 nickName[11], nickNameLength, comment[27], commentLength;
} OSOwnerInfo;

typedef struct DwcRapErrorInfo {
    int errorCode;
    int errorType;
    int dwcError;
    int gameCode;
} DwcRapErrorInfo;

void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203D5EC(void);
extern u32 func_0203D610(void);
u32 func_020307B0(void *block);
extern int func_0216B908(void);
extern int func_0205CCD8(void);
int func_02059E38(int *errorCode, int *errorType);
void func_0203C9AC(int errorCode, u32 errorType, u32 dwcError, u32 gameCode);
u32 func_0203CA98(void);
void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
void func_02034714(const char *expr, u32 line, const char *file);
int func_020597C8(struct DWCstAccUserData *userdata);
int func_02059760(struct DWCstAccUserData *userdata);
extern void func_0203D7FC(void *);
extern void func_02059F18(void);
void func_0205C6AC(void *inetControl, u16 dmaNo, u16 powerMode, u16 priority);
void func_0205C758(void);
int func_0205C88C(void);
int func_0205CA20(void);
void func_0205C8E0(void);
void func_0216AB20(void *userData, int productId, char *gameName, int secretKey, int sakeAppId, void *friendList, int friendListLen);
void func_02087C88(struct OSOwnerInfo *info);
int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
void func_0216AE88(void);
int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
int func_02168994(void (*callback)(int, void *), void *param);
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc);
void func_02082BCC(void *dst, int value, int size);
u32 func_02094530(char *dst, u32 format, ...);
u32 func_0203F004(const u8 *str);
u32 func_0203D650(void);
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_02177138(int callback, int param);
int func_02177160(int callback, int param);
int func_0216B634(int callback, int param);
int func_02177188(int callback, int param);
int func_0216B65C(void);
void func_02082D44(void *src, void *dst, int size);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
unsigned char func_0216B838(void);
int func_0205984C(void *userdata);
void func_02059870(int userData);
int func_02177270(u8 aid, int timeoutMs);
int func_021AEF44(int aid, int data, int size);
extern int func_0216B804(void);
extern void func_0203A338(u32);
extern void func_0205CC20(void);
extern u32 func_020111E8(void);
extern void func_0216AD50(void);
extern int func_021C5B80(void);
extern void DWC_GdbShutdown(void);
extern int func_0216B94C(u8);
extern int func_02176DEC(int a);
void func_021AEE14(int);
int func_021AF238(u32 aidBitmap, int myAid);
extern void func_021AEF6C(void *, int, int);
extern void func_021AF18C(void (*cb)(void));
extern void func_021AF1A0(void);
extern int func_021AF2AC(int);
extern void func_021AF30C(int);
extern int _s32_div_f(int, int);
extern void func_021AF13C(void);
extern int func_0205912C(u8 *);
extern unsigned char func_02168848(void *p, int a, int b);
extern int func_021688FC(char *, unsigned long);
int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_0216B408(int, int, void *, u32, void *, u32, void *, int *, u32);
extern void func_0216B7E0(u8);
extern int func_021AF210(void);
extern void func_021770EC(u8, u32, u32);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int id);
extern void func_021B6100(void);
extern void *func_02060C5C(void *start, u32 size, u16 attr);
extern u32 func_02060F18(char *p, u32 v);
extern u16 func_02060F40(char *p, u16 v);
extern void func_02060C94(void *heap);
extern void func_020306F0(u32 heap);
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, int align);
extern void func_0200FB6C(void);
extern u8 func_02060F98(char *p);
extern void func_02060E30(struct ExpHeap *heap, void *block);
extern int func_02059F6C(void *a, u32 b, void *c, void *d);
extern void MIi_CpuClearFast(unsigned int data, void *destp, unsigned int size);
extern int func_02059718(struct DWCstAccUserData *userdata);
extern void DWC_CreateUserData(void *userdata);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern int func_0203CD98(void);
extern u32 func_0200FB24(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_0200FB38(void);
extern void func_0200FB4C(unsigned int x);
extern void func_0200F7C0(u32 value);
extern void func_0200FAAC(void);
extern void func_0203C554(u32 a);
void func_02155160(int heapId);
int func_02155168(int heapId, int param);
int func_021551B0(void (*doneCallback)(int));
int func_021551D4(int cancelRequest);
int func_021551DC(void *requestClose);
int func_02155204(void (*doneCallback)(int));
int func_02155234(void *matchValue, int maxPlayers, int useFilter, int unused);
int func_0215523C(int friendIndex, int maxPlayers, int limitToTwo);
int func_02155244(int requestClose);
int func_02155264(int data, int size, int unused, void (*doneCallback)(int));
int func_02155280(int callback);
int func_0215528C(void);
int func_02155294(void);
int func_021552AC(void);
int func_021552C4(void);
int func_021552CC(void);
int func_021552D4(void);
int func_021552DC(void);
int func_021552E8(void);
void func_02155330(u32 enabled);
int func_02155338(int friendIndex);
s16 func_0215534C(void);
int func_02155354(void);
void func_0215535C(u32 allowed);
int func_02155364(void);
void *func_0215536C(void);
void func_02155374(int state);
int func_02155388(void);
int func_0215539C(int userData, int friendList);
void func_021554A0(void);
int func_021554C8(void);
void func_02155648(int serverFunc, int clientFunc);
void func_02155664(void (*acceptFunc)(void));
void func_02155674(void);
u8 func_02155678(void);
int func_0215568C(void *matchValue, int maxPlayers, int useFilter, int unused);
int func_0215580C(int filter, int maxPlayers, int evalFunc, int evalParam);
void func_02155904(void);
int func_0215592C(int cancelRequest);
int func_02155A80(void *data, int size, int packetType);
int func_02155B00(int data, int size);
int func_02155B14(int data, int size);
void func_02155B68(void);
void func_02155B98(int error);
void func_02155BDC(unsigned int aid);
void func_02155C0C(int error);
void func_02155C24(void);
void func_02155C28(int deletedIndex, int srcIndex);
void func_02155C6C(void);
void func_02155C70(void);
void func_02155C8C(void);
void func_02155D2C(int peerIndex);
void func_02155D3C(int error, int cancel, int self, int isServer, int peerIndex);
int func_02155D7C(void);
void func_02155D80(int size, u32 aid);
void func_02155DA4(unsigned int header);
void func_02155DCC(u32 aid, u8 *data, int size);
void func_02155E9C(int error, int isLocal, int isServer, u32 aid);
int func_02155F58(void);
int func_0215610C(void);
int func_0215615C(u32 counterIndex);
int func_021561C0(void);
int func_021562EC(void);
void func_0215631C(void);
void func_02156330(void);
void func_02156344(void *heapId);
void func_021563C0(int unused);
void func_021563D0(void);
int func_021563EC(void);
void func_02156400(void);
void func_0215642C(int lock);
int func_02156460(int errorCode, int errorType);
int func_02156690(int pollOnly);
int func_02156730(void);
void func_0215677C(void);
void func_021567B8(void);
int func_0215683C(char *data, int size);
int func_02156860(int friendIndex);
unsigned char func_02156874(int friendIndex);
int func_02156888(int friendIndex, int maxPlayers, int limitToTwo);
int func_02156A3C(void);
void func_02156A58(int error, int cancel, int self, int isServer, int peerIndex);
void func_02156B18(int error, int cancel, int self, int isServer, int peerIndex);
void func_02156B3C(int aid);
int func_02156B68(char *unused);
s16 func_02156B70(void);
int func_02156B8C(void);
int func_02156BA8(void);
void func_02156BC4(int enabled);
void func_02156BD8(u32 aid);
void func_02156C00(u32 aid);
void func_02156C60(void);
unsigned char func_02156C84(void);
void func_02156C98(int unused);
int func_02156CAC(void);
int func_02156CD0(void);
void func_02156CF4(void);
u32 func_02156D5C(void);
void func_02156D70(u32 allowed);
int func_02156D84(void);
void func_02156DB0(u32 enabled);
void func_02156DC4(int (*errorFunc)(u32, u32, u32, int), u32 errorArg);
void func_02156DE0(int (*hookFunc)(u32, u32, u32, int), u32 hookArg);
void func_02156DFC(int heapId);
void func_02156E24(int ownerId, int size, int heapId);
void func_02156E30(u32 ownerId, u32 size, u32 minRequestSize, u32 heapId);
void func_02156ED0(void);
void func_02156F14(void);
void func_02156F50(int tag);
u32 func_02156F5C(u32 ownerId, u32 size, u32 align);
void func_02156FDC(u32 ownerId, void *block, int unused);
void func_02157048(u32 heapId, u32 size);
void func_021570B8(void);
int func_02157108(u16 heapId);
void func_02157138(void *userData);
void func_02157160(void);
int func_02157170(int hasSession, int keepError);
extern int *_pSetupParam;
extern char _sNetDevwifiFile[];
extern DwcRapWork *_pRapWork;
extern char _wifiDeviceTable[];
extern char _sAssertEmpty[];
extern char _sDwcRapFile[];
/* stand-in: second name for the address of _pRapWork; with one name the compiler shares the literal-pool word and the bytes change. */
extern char _pRapWorkAddr[];
extern char _sGameName[];
extern char _sMatchKey[];
extern char _sMatchFilterFormat[];
extern unsigned char abs_id_11[];
extern DwcRapHeap *_pRapHeap;
extern char _sAssertEmptyCommon[];
extern char _sDwcRapCommonFile[];
extern char _sDwcGameName[];





























void func_02155160(int heapId)
{
    func_02156DFC(heapId);
}





























int func_02155168(int heapId, int param)
{
    DwcRapNetInit *netInit;

    if (_pSetupParam != 0)
        return 0;
    netInit = func_0203D798();
    func_02157048(netInit->wifiHeapId, netInit->heapSize);
    _pSetupParam = func_02030734(heapId, 8, 1, _sNetDevwifiFile, 0xba);
    *_pSetupParam = param;
    return 1;
}




























int func_021551B0(void (*doneCallback)(int))
{
    u32 userData;
    int result;
    userData = func_0203D5EC();
    result = func_0215539C(userData, func_0203D610());
    if (doneCallback) doneCallback(1);
    return result;
}




























int func_021551D4(int cancelRequest)
{
    return func_0215592C(cancelRequest);
}




























/*
 * Null-pointer guard through func_02156690, then either func_02156730 or func_0215592C.
 */
int func_021551DC(void *requestClose)
{
    int func_02156690(int);
    int func_02156730(void);
    int func_0215592C(int cancelRequest);
    int pollOnly;
    if (requestClose == 0) pollOnly = 1;
    else pollOnly = 0;
    if (func_02156690(pollOnly)) {
        func_02156730();
        return 1;
    }
    func_0215592C((int)requestClose);
    return 1;
}



























int func_02155204(void (*doneCallback)(int))
{
    if (_pSetupParam != 0) {
        func_0215677C();
        if (doneCallback != 0)
            doneCallback(1);
        func_020307B0(_pSetupParam);
        _pSetupParam = 0;
    }
    func_021570B8();
    return 1;
}




























int func_02155234(void *matchValue, int maxPlayers, int useFilter, int unused)
{
    return func_0215568C(matchValue, maxPlayers, useFilter, unused);
}



























int func_0215523C(int friendIndex, int maxPlayers, int limitToTwo)
{
    return func_02156888(friendIndex, maxPlayers, limitToTwo);
}




























int func_02155244(int requestClose)
{
    int func_02156690(int);
    int func_02156730(void);
    int pollOnly;
    if (requestClose == 0) pollOnly = 1;
    else pollOnly = 0;
    if (func_02156690(pollOnly)) {
        func_02156730();
        return 1;
    }
    return 0;
}



























int func_02155264(int data, int size, int unused, void (*doneCallback)(int))
{
    if (func_02155B14(data, size)) {
        if (doneCallback) doneCallback(1);
        return 1;
    }
    return 0;
}



























/*
 * Calls func_02155648 on the argument twice and returns 1.
 */
int func_02155280(int callback)
{
    func_02155648(callback, callback);

    return 1;
}



























int func_0215528C(void)
{
    return func_02155388();
}


























/*
 * False when the word call returns -1.
 */
int func_02155294(void)
{
    if (func_021562EC() != -1) {
        return 1;
    }

    return 0;
}


























/*
 * True when no session is open or the state machine reports a lost connection.
 */
int func_021552AC(void)
{
    int offline;
    offline = func_02156D84();
    if (!func_02155388()) offline |= 1;
    return offline;
}


























int func_021552C4(void)
{
    return func_02156CAC();
}


























int func_021552CC(void)
{
    return func_0216B908();
}


























int func_021552D4(void)
{
    return func_021562EC();
}



























/*
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 */
int func_021552DC(void)
{
    return 3 - func_0205CCD8();
}



























int func_021552E8(void)
{
    int errorCode, errorType, dwcError;

    dwcError = func_02059E38(&errorCode, &errorType);
    if (dwcError != 0)
        func_0203C9AC(errorCode, errorType, dwcError, 0);
    if (dwcError == 0)
        return 0;
    if (errorCode == 0)
        return -10000;
    dwcError = ((int *)func_0203CA98())[3];
    if (dwcError == 0)
        dwcError = errorCode;
    return dwcError;
}


























void func_02155330(u32 enabled)
{
    func_02156DB0(enabled);
}
























/*
 * True when the friend is in the waiting-for-a-partner status.
 */
int func_02155338(int friendIndex)
{
    if (func_02156874(friendIndex) == 6) return 1;
    return 0;
}
























s16 func_0215534C(void)
{
    return func_02156B70();
}
























int func_02155354(void)
{
    return func_02156B8C();
}
























void func_0215535C(u32 allowed)
{
    func_02156D70(allowed);
}
























int func_02155364(void)
{
    return func_02156CD0();
}

























/*
 * Address of the module state object.
 */
void *func_0215536C(void)
{
    return _wifiDeviceTable;
}

























/*
 * Stores a word at +0x754 of the block the pointer holds.
 */
void func_02155374(int state)
{
    _pRapWork->state = state;
}

























/*
 * True when the block pointer is set.
 */
int func_02155388(void)
{
    return _pRapWork != 0;
}

























/*
 * Allocates the 0x7AC-byte ov009 work block into _pRapWork (asserting it
 * was empty) and initialises it.  func_0203D7C8's last two arguments look
 * like a file/line pair (_sDwcRapFile, 302).
 */
int func_0215539C(int userData, int friendList)
{
    DwcRapNetInit *netInit;
    int slot;

    netInit = func_0203D798();
    if (_pRapWork != 0)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    _pRapWork = func_0203D7C8(netInit->heapId, sizeof(DwcRapWork), _sDwcRapFile, 302);
    for (slot = 0; slot < 32; slot++)
        _pRapWork->deletedFriendIndex[slot] = -1;
    func_02155374(DWC_RAP_STATE_START);
    _pRapWork->vchatPlayerCount = 0;
    _pRapWork->targetFriendIndex = -1;
    _pRapWork->maxPlayers = netInit->maxConnectNum;
    _pRapWork->newClientAid = -1;
    _pRapWork->vchatEnabled = 0;
    _pRapWork->forceFatalError = 0;
    _pRapWork->vchatLocalOn = 1;
    _pRapWork->vchatPeerOn = 1;
    _pRapWork->vchatGateOpen = 1;
    _pRapWork->userData = (void *)userData;
    _pRapWork->friendList = (u8 *)friendList;
    _pRapWork->connectArmed = 1;
    for (slot = 0; slot < 32; slot++)
        _pRapWork->friendStatus[slot] = 0;
    if (func_020597C8((struct DWCstAccUserData *)_pRapWork->userData) == 0)
        return 1;
    if (func_02059760((struct DWCstAccUserData *)_pRapWork->userData) == 0)
        return 2;
    return 0;
}
























/*
 * func_02156C60 receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 */
void func_021554A0(void)
{
    if (_pRapWork) {
        func_0203D798();
        func_02156C60();
        func_0203D7FC(_pRapWork);
        _pRapWork = 0;
    }
    func_02059F18();
}
























/*
 * Login half of the state machine (states START to MATCH idle): connect to
 * the access point, init friends match, log in, update the friend list.
 * Returns the result code to report, or the error handler result.
 */
int func_021554C8(void)
{
    OSOwnerInfo ownerInfo;
    void *friendListArg;
    int friendFlags;
    int result;

    switch (_pRapWork->state) {
    case DWC_RAP_STATE_START:
        func_0203D798();
        func_0205C6AC(_pRapWork->inetWork, 2, 1, 0x14);
        func_0205C758();
        func_02155374(DWC_RAP_STATE_WAIT_INET);
        _pRapWork->vchatActive = 0;
    case DWC_RAP_STATE_WAIT_INET:
        if (func_0205C88C() != 0) {
            if (func_0205CA20() == 4)
                func_02155374(DWC_RAP_STATE_INIT_LOGIN);
            else
                func_02155374(DWC_RAP_STATE_ERROR);
        } else {
            func_0205C8E0();
            break;
        }
    case DWC_RAP_STATE_INIT_LOGIN:
        result = func_02155F58();
        if (result != 0)
            return result;
        friendFlags = 0;
        friendListArg = _pRapWork->friendList;
        if (friendListArg != 0)
            friendFlags = 0x20;
        func_0216AB20(_pRapWork->userData, 0x2FC6, _sGameName, 0, 0, friendListArg, friendFlags);
        _pRapWork->friendsMatchInit = 1;
        { u16 ingameName[2] = {0, 0};
        func_02087C88((struct OSOwnerInfo *)(&ownerInfo));
        func_0216B0E0(ingameName, 0, (void (*)(int,  int,  void *))((VoidFunc)func_02155B98), 0);
        }
        func_02155374(DWC_RAP_STATE_LOGIN);
    case DWC_RAP_STATE_LOGIN:
        func_0216AE88();
        break;
    case DWC_RAP_STATE_UPDATE_SERVERS:
        if (_pRapWork->friendList != 0) {
            if (func_0216B1E0(0, func_02155C0C, _pRapWork->userData,
                              func_02155C24, _pRapWorkAddr, func_02155C28,
                              _pRapWorkAddr) == 0) {
                func_0203C9AC(0, 0, 0, DWC_RAP_RESULT_FATAL);
            } else {
                func_02168994((void (*)(int,  void *))func_02155C6C, 0);
                func_0216AE88();
            }
        }
        func_02155374(DWC_RAP_STATE_WAIT_UPDATE);
        break;
    case DWC_RAP_STATE_WAIT_UPDATE:
        func_0216AE88();
        if (_pRapWork->friendList == 0)
            func_02155374(DWC_RAP_STATE_IDLE);
        break;
    case DWC_RAP_STATE_IDLE:
        func_0216AE88();
        { int resultCode = DWC_RAP_RESULT_IDLE; _pRapWork->result = resultCode; return resultCode; }
    }
    return func_02155F58();
}
























/*
 * Stores two words at +0x27C and +0x280 of the block the module pointer holds.
 */
void func_02155648(int serverFunc, int clientFunc)
{
    _pRapWork->serverRecvFunc = (DwcRapRecvFunc)serverFunc;
    _pRapWork->clientRecvFunc = (DwcRapRecvFunc)clientFunc;
}























/*
 * Sets the callback that decides whether a joining friend is accepted.
 */
void func_02155664(void (*acceptFunc)(void))
{
    _pRapWork->acceptFriendFunc = (int (*)(int, u32))acceptFunc;
}






















/*
 * New client callback of the match calls; nothing to do.
 */
void func_02155674(void)
{
}























/*
 * Connect attempt callback of the match calls; answers with the allowConnect flag.
 */
u8 func_02155678(void)
{
    return _pRapWork->allowConnect;
}























/*
 * Starts a match search for any partner: builds the "key = value" filter string,
 * resets the receive buffers, enters the matching state and registers the
 * transport callbacks.
 */
int func_0215568C(void *matchValue, int maxPlayers, int useFilter, int unused)
{
    int slot;

    if (_pRapWork == 0)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    if (_pRapWork->state != DWC_RAP_STATE_IDLE)
        return 0;
    func_02156C60();
    if (func_0216CA04(0, _sMatchKey, matchValue) == 0)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    func_02082BCC(_pRapWork->matchFilter, 0, 0x80);
    func_02094530(_pRapWork->matchFilter, (u32)_sMatchFilterFormat, _sMatchKey, matchValue);
    if ((int)func_0203F004((const u8 *)_pRapWork->matchFilter) >= 0x80)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    if (useFilter)
        func_0216CA04(1, _pRapWork->matchFilter, _pRapWork->matchFilter);
    for (slot = 0; slot < maxPlayers; slot++)
        func_02156C00(slot);
    func_02155374(DWC_RAP_STATE_MATCHING);
    _pRapWork->maxPlayers = maxPlayers;
    if (func_0216B284(2, maxPlayers, _pRapWork->matchFilter, (VoidFunc)func_02155D3C,
                      (void *)func_0203D650(), func_02155674,
                      (void *)func_0203D650(), (VoidFunc)func_02155D7C,
                      (void *)func_0203D650(), (VoidFunc)func_02155678,
                      &_pRapWork->connectionUserData, (void *)func_0203D650()) == 0)
        return 0;
    _pRapWork->connectMode = 0;
    func_02177138((int)((VoidFunc)func_02155D80), 0);
    func_02177160((int)((VoidFunc)func_02155DCC), 0);
    func_0216B634((int)((VoidFunc)func_02155E9C), 0);
    func_02177188((int)((VoidFunc)func_02155BDC), 0);
    _pRapWork->sendInFlight = 0;
    _pRapWork->connectArmed = 1;
    return 1;
}























/*
 * Starts a match search with a caller supplied filter string; otherwise like
 * the key version.
 */
int func_0215580C(int filter, int maxPlayers, int evalFunc, int evalParam)
{
    int slot;

    if (_pRapWork == 0)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    if (_pRapWork->state != DWC_RAP_STATE_IDLE)
        return 0;
    func_02156C60();
    for (slot = 0; slot < maxPlayers; slot++)
        func_02156C00(slot);
    func_02155374(DWC_RAP_STATE_MATCHING);
    _pRapWork->maxPlayers = maxPlayers;
    if (func_0216B284(1, maxPlayers, (char *)filter, (VoidFunc)func_02155D3C, 0, func_02155674, 0, (void *)evalFunc, (void *)evalParam,
                      0, 0, 0) == 0)
        return 0;
    _pRapWork->connectMode = 0;
    func_02177138((int)((VoidFunc)func_02155D80), 0);
    func_02177160((int)((VoidFunc)func_02155DCC), 0);
    func_0216B634((int)((VoidFunc)func_02155E9C), 0);
    func_02177188((int)((VoidFunc)func_02155BDC), 0);
    _pRapWork->sendInFlight = 0;
    _pRapWork->connectArmed = 1;
    _pRapWork->result = DWC_RAP_RESULT_IDLE;
    return 1;
}






















/*
 * Sets 0xd through func_02155374 when the word at +0x754 is 0xc, else 0xb.
 */
void func_02155904(void)
{
        void func_02155374(int state);
    if (_pRapWork->state == DWC_RAP_STATE_MATCH_FAILING) {
        func_02155374(DWC_RAP_STATE_MATCH_FAILED);
        return;
    }
    func_02155374(DWC_RAP_STATE_CANCELED);
}




















static inline int SetResult(int result)
{
    _pRapWork->result = result;
    return result;
}




















int func_0215592C(int cancelRequest)
{
    func_02155B68();
    switch (_pRapWork->state) {
    case DWC_RAP_STATE_START:
    case DWC_RAP_STATE_WAIT_INET:
    case DWC_RAP_STATE_INIT_LOGIN:
    case DWC_RAP_STATE_LOGIN:
    case DWC_RAP_STATE_UPDATE_SERVERS:
    case DWC_RAP_STATE_WAIT_UPDATE:
        return func_021554C8();
    case DWC_RAP_STATE_MATCHING:
        if (cancelRequest != 0)
            func_02155374(DWC_RAP_STATE_CANCELING);
        if (_pRapWork->connectMode == 2 && _pRapWork->targetFriendIndex >= 0
            && _pRapWork->friendStatus[_pRapWork->targetFriendIndex] != 6)
            func_02155374(DWC_RAP_STATE_MATCH_FAILING);
        break;
    case DWC_RAP_STATE_CANCELING:
    case DWC_RAP_STATE_MATCH_FAILING:
        func_0216B65C();
        func_02155904();
        break;
    case DWC_RAP_STATE_CONNECTED: {
        DwcRapNetInit *netInit = func_0203D798();
        if (_pRapWork->vchatEnabled != 0)
            func_02156344((void *)netInit->heapId);
        _pRapWork->vchatLocalOn = 0;
        func_02155374(DWC_RAP_STATE_IN_SESSION);
        return SetResult(DWC_RAP_RESULT_CONNECTED);
    }
    case DWC_RAP_STATE_CANCELED:
        func_02155374(DWC_RAP_STATE_IDLE);
        _pRapWork->sendInFlight = 0;
        _pRapWork->newClientAid = -1;
        return SetResult(DWC_RAP_RESULT_CANCELED);
    case DWC_RAP_STATE_MATCH_FAILED:
        func_02155374(DWC_RAP_STATE_IDLE);
        _pRapWork->sendInFlight = 0;
        _pRapWork->newClientAid = -1;
        return SetResult(DWC_RAP_RESULT_MATCH_FAILED);
    case DWC_RAP_STATE_ERROR:
        return func_02155F58();
    case DWC_RAP_STATE_CLOSING:
        if (_pRapWork->vchatActive == 0) {
            func_0216B65C();
            func_02155374(DWC_RAP_STATE_CLOSED);
            break;
        }
    case DWC_RAP_STATE_IDLE: {
        int result = func_021561C0();
        if (result == 0)
            return SetResult(DWC_RAP_RESULT_IDLE);
        return result;
    }
    }
    return func_021561C0();
}




















int func_02155A80(void *data, int size, int packetType)
{
    int aidBitmap;

    if (size >= 0x100)
        return 0;
    if (_pRapWork->sendInFlight != 0)
        return 0;
    _pRapWork->sendHeader.word = packetType | (_pRapWork->vchatLocalOn << 8);
    _pRapWork->sendSeq = _pRapWork->sendSeq + 1;
    _pRapWork->sendHeader.octet[2] = _pRapWork->sendSeq;
    func_02082D44(data, _pRapWork->sendPayload, size);
    _pRapWork->sendInFlight = 1;
    aidBitmap = (u16)func_0216B908();
    if (aidBitmap != func_02176FD4(aidBitmap, _pRapWork, size + 4)) {
        _pRapWork->sendInFlight = 0;
        return 0;
    }
    return 1;
}




















/*
 * Flag test on the three-argument call.
 */
int func_02155B00(int data, int size)
{
    if (func_02155A80((void *)data, size, 3) != 0) {
        return 1;
    }

    return 0;
}


















int func_02155B14(int data, int size)
{
    if (_pRapWork->sendStateReady == 0)
        return 0;
    if (func_02155A80((void *)data, size, 1) == 0)
        return 0;
    _pRapWork->sendStateReady = 0;
    if (_pRapWork->clientRecvFunc != 0) {
        int myAid = func_0216B838();
        _pRapWork->clientRecvFunc(myAid, (u8 *)data, (u16)size);
    }
    return 1;
}
















void func_02155B68(void)
{
    int ackValue;
    if (_pRapWork->ackPending) {
        ackValue = 0;
        if (func_02155B00((int)&ackValue, 4))
            _pRapWork->ackPending = 0;
    }
}
















void func_02155B98(int error)
{
    if (func_0205984C((void *)_pRapWork->userData) != 0) {
        func_02059870((int)_pRapWork->userData);
        _pRapWork->userDataChanged = 1;
    }
    if (error == 0)
        func_02155374(DWC_RAP_STATE_UPDATE_SERVERS);
    else
        func_02155374(DWC_RAP_STATE_ERROR);
}
















void func_02155BDC(unsigned int aid)
{
    if (aid < 2 && _pRapWork->peerAlive) {
        func_0216B65C();
        _pRapWork->newClientAid = -1;
        func_02155374(DWC_RAP_STATE_TIMED_OUT);
    }
}

















void func_02155C0C(int error)
{
    if (error == 0) {
        func_02155374(DWC_RAP_STATE_IDLE);
        return;
    }

    func_02155374(DWC_RAP_STATE_ERROR);
}
















/*
 * Friend status callback of the update call; nothing to do.
 */
void func_02155C24(void)
{
}

















/*
 * Stores a and b into every one of 0x20 slots at +0x17C and +0x1FC whose first word is -1.
 */
void func_02155C28(int deletedIndex, int srcIndex)
{
    int slot;

    func_0203D798();
    for (slot = 0; slot < 0x20; slot++) {
        if (_pRapWork->deletedFriendIndex[slot] == -1) {
            _pRapWork->deletedFriendIndex[slot] = deletedIndex;
            _pRapWork->deletedFriendSrcIndex[slot] = srcIndex;
        }
    }
}
















void func_02155C6C(void)
{
}















/*
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 */
void func_02155C70(void)
{
    func_02082BCC((char *)_pRapWork->peerCounter, 0, 8);
}















void func_02155C8C(void)
{
    int aid, peer;

    for (aid = 0; aid < 2; aid++)
        func_02177270(aid, 0);
    if (func_0216B838() == 0) {
        for (peer = 0; peer < _pRapWork->maxPlayers; peer++) {
            if (peer != func_0216B838() && (func_0216B908() & (1 << peer)) != 0) {
                if (func_02177270(peer, 10000) == 0)
                    func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
            }
        }
    } else {
        if (func_02177270(0, 10000) == 0)
            func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    }
    _pRapWork->peerAlive = 1;
    func_02155C70();
}















/*
 * Enables slot 9 then calls the wakeup.
 */
void func_02155D2C(int peerIndex)
{
    func_02155374(DWC_RAP_STATE_CONNECTED);
    func_02155C8C();
}













void func_02155D3C(int error, int cancel, int self, int isServer, int peerIndex)
{
    DwcRapWork *work;

    if (error == 0) {
        if (cancel == 0)
            func_02155D2C(peerIndex);
        else
            func_02155904();
    } else {
        func_02155374(DWC_RAP_STATE_ERROR);
    }
    work = _pRapWork;
    if (work->connectEventFunc != 0) {
        int myAid = func_0216B838();
        _pRapWork->connectEventFunc(myAid, work->connectEventArg);
    }
}












/*
 * Evaluate callback of the match calls; accepts every candidate.
 */
int func_02155D7C(void)
{
    return 1;
}













/*
 * User send callback of the transport: the packet went out.
 */
void func_02155D80(int size, u32 aid)
{
    if (aid < 2) {
        _pRapWork->sendInFlight = 0;
        _pRapWork->peerCounter[aid] = 0;
    }
}










void func_02155DA4(unsigned int header)
{
    if (header & 0x100) {
        _pRapWork->vchatPeerOn = 1;
    } else {
        _pRapWork->vchatPeerOn = 0;
    }
}











void func_02155DCC(u32 aid, u8 *data, int size)
{
    u32 header = data[0] | ((data[3] << 24) | (data[2] << 16) | (data[1] << 8));

    if (aid >= 2)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    if (aid < 2) {
        _pRapWork->peerAlive = 1;
        if ((u8)header == 1) {
            func_02155DA4(header);
            _pRapWork->lastRecvSeq = data[2];
            _pRapWork->ackPending = 1;
        } else if ((u8)header == 3) {
            _pRapWork->sendStateReady = 1;
            return;
        } else {
            if (func_021AEF44(aid, (int)data, size) == 0)
                return;
            return;
        }
        if (func_0216B838() == 0) {
            if (_pRapWork->serverRecvFunc != 0)
                _pRapWork->serverRecvFunc(aid, data + 4, (u16)(size - 4));
        } else {
            if (_pRapWork->clientRecvFunc != 0)
                _pRapWork->clientRecvFunc(aid, data + 4, (u16)(size - 4));
        }
    }
}











void func_02155E9C(int error, int isLocal, int isServer, u32 aid)
{
    if (aid < 2) {
        _pRapWork->sendInFlight = 0;
        _pRapWork->peerCounter[2] = 0;
        _pRapWork->connectPending = 0;
        if (error == 0) {
            if (_pRapWork->connectArmed == 1 && func_0216B804() == 1) {
                if (_pRapWork->state != DWC_RAP_STATE_CANCELING) {
                    func_02155374(DWC_RAP_STATE_CLOSING);
                }
                if (_pRapWork->vchatActive != 0) {
                    func_02156400();
                }
            }
            if (isLocal == 0) {
                func_02155374(DWC_RAP_STATE_CLOSING);
            }
        }
        if (_pRapWork->errorOnDisconnect != 0) {
            u32 *errorInfo = (u32 *)func_0203CA98();
            if (errorInfo[3] == 0) {
                func_0203C9AC(errorInfo[0], errorInfo[1], errorInfo[2], DWC_RAP_RESULT_DISCONNECT_ERROR);
            }
        }
        func_0203A338(aid);
        {
            void (*closedFunc)(u32, u32) = _pRapWork->connectionClosedFunc;
            if (closedFunc != 0) {
                closedFunc(aid, _pRapWork->connectionClosedArg);
            }
        }
    }
}












/*
 * Handles a DWC error: runs the error callbacks, then reacts by error type.
 * The goto into the case 4 body keeps the short branch of the original.
 */
int func_02155F58(void)
{
    int errorCode, errorType;
    int dwcError;
    u32 result;
    u32 code = 0;
    int (*hookFunc)(u32, u32, u32, int);

    dwcError = func_02059E38(&errorCode, &errorType);
    if (dwcError == 0) goto useCode;
    hookFunc = _pRapWork->errorHookFunc;
    if (hookFunc != 0) {
        if (hookFunc(_pRapWork->errorHookArg, errorCode, errorType, dwcError) == 1)
            return code;
    }
    hookFunc = _pRapWork->errorFunc;
    if (hookFunc != 0)
        hookFunc(_pRapWork->errorArg, errorCode, errorType, dwcError);
    code = errorCode;
    if (errorCode == 0 || errorType == 1)
        code = dwcError;
    result = code;
    switch (errorType) {
    case 1:
        func_02059F18();
        if (_pRapWork != 0 && _pRapWork->state == DWC_RAP_STATE_ERROR)
            func_02155374(DWC_RAP_STATE_IDLE);
        break;
    case 2:
        if (errorCode <= -40000 && errorCode >= -41999)
            DWC_GdbShutdown();
        if (_pRapWork != 0 && _pRapWork->state == DWC_RAP_STATE_ERROR)
            func_02155374(DWC_RAP_STATE_IDLE);
        break;
    case 4:
        if (errorCode <= -40000 && errorCode >= -41999) {
            DWC_GdbShutdown();
        useCode:
            result = code;
        }
        break;
    case 5:
        func_021C5B80();
        break;
    case 3:
    case 6:
        if (_pRapWork != 0) {
            switch (_pRapWork->state) {
            case DWC_RAP_STATE_LOGIN: case DWC_RAP_STATE_IDLE: case DWC_RAP_STATE_MATCHING: case DWC_RAP_STATE_CANCELING: case DWC_RAP_STATE_CONNECTED: case DWC_RAP_STATE_IN_SESSION: case DWC_RAP_STATE_CANCELED:
            case DWC_RAP_STATE_ERROR: case DWC_RAP_STATE_CLOSING: case DWC_RAP_STATE_CLOSED: case DWC_RAP_STATE_TIMED_OUT:
                if (_pRapWork->friendsMatchInit == 1) {
                    func_0216AD50();
                    _pRapWork->friendsMatchInit = 0;
                }
                /* fall through */
            case DWC_RAP_STATE_START: case DWC_RAP_STATE_WAIT_INET: case DWC_RAP_STATE_INIT_LOGIN:
                func_0205CC20();
                break;
            default:
                break;
            }
        }
        if (_pRapWork != 0)
            func_02155374(DWC_RAP_STATE_FATAL_DISCONNECT);
        break;
    case 7:
        if (_pRapWork != 0) {
            func_02155374(DWC_RAP_STATE_FATAL_ERROR);
            if (_pRapWork->fatalErrorFunc != 0)
                _pRapWork->fatalErrorFunc(-errorCode);
        }
        break;
    default:
        break;
    }
    if (_pRapWork->forceFatalError != 0) {
        result = DWC_RAP_RESULT_FATAL;
        func_0203C9AC(errorCode, errorType, dwcError, result);
    } else if (_pRapWork->state == DWC_RAP_STATE_TIMED_OUT) {
        result = DWC_RAP_RESULT_TIMEOUT_ERROR;
        func_0203C9AC(errorCode, errorType, dwcError, result);
    } else if (dwcError != 0) {
        func_0203C9AC(errorCode, errorType, dwcError, 0);
        func_020111E8();
    }
    return result;
}












int func_0215610C(void)
{
    int aid;
    int hasPeer = 0;
    for (aid = 0; aid < _pRapWork->maxPlayers; aid++) {
        if (aid != func_0216B838() && func_0216B94C(aid)) {
            hasPeer = 1;
            if (func_02176DEC((u8)aid) == 0) {
                return 0;
            }
        }
    }
    return hasPeer;
}












int func_0215615C(u32 counterIndex)
{
    if (_pRapWork->sendInFlight == 0 && func_0215610C() != 0
        && (func_0216B908() & 0xFFFE) != 0) {
        _pRapWork->sendInFlight = 1;
        _pRapWork->sendHeader.word = ((u32)_pRapWork->vchatLocalOn << 8) | 2;
        func_02176FD4(func_0216B908(), _pRapWork, 4);
        _pRapWork->peerCounter[counterIndex] = 0;
        return 1;
    }
    return 0;
}












int func_021561C0(void)
{
    DwcRapWork *work;
    int peer;

    func_02156CF4();
    func_0216AE88();
    func_021567B8();
    if (_pRapWork->vchatActive != 0) {
        int muteVchat;
        if (_pRapWork->vchatLocalOn == 1 && _pRapWork->vchatPeerOn == 1 && _pRapWork->vchatGateOpen == 1)
            muteVchat = 0;
        else
            muteVchat = 1;
        func_021AEE14(muteVchat);
        work = _pRapWork;
        if (work->vchatAidBitmap != func_0216B908() && work->vchatTalkLock == 0 && work->vchatEnabled != 0) {
            if (func_021AF238(func_0216B908(), func_0216B838()) != 0)
                _pRapWork->vchatAidBitmap = func_0216B908();
        }
    }
    if (_pRapWork->state == DWC_RAP_STATE_TIMED_OUT) {
        int result = func_02155F58();
        if (result == 0)
            return DWC_RAP_RESULT_TIMED_OUT;
        return result;
    }
    if (_pRapWork->state == DWC_RAP_STATE_CLOSED)
        return DWC_RAP_RESULT_CLOSED;
    if (_pRapWork->state == DWC_RAP_STATE_CONNECTED || _pRapWork->state == DWC_RAP_STATE_IN_SESSION) {
        for (peer = 0; peer < _pRapWork->maxPlayers; peer++) {
            if (_pRapWork->peerCounter[peer]++ >= 0xf0 && _pRapWork->sendInFlight == 0 && func_0215615C(peer) != 0) {
                func_02155C70();
                break;
            }
        }
    }
    return func_02155F58();
}












/*
 * Three functions: 0x021562EC, 0x0215631C, 0x02156330.
 */
int func_021562EC(void)
{
    DwcRapWork *work = _pRapWork;
    if (work != 0) {
        u32 state = work->state;
        if (state == DWC_RAP_STATE_CONNECTED || state == DWC_RAP_STATE_IN_SESSION || state == DWC_RAP_STATE_CLOSING) {
            return func_0216B838();
        }
    }
    return -1;
}












void func_0215631C(void)
{
    _pRapWork->vchatActive = 0;
}












void func_02156330(void)
{
    _pRapWork->vchatLocalOn = 1;
}












/*
 * Start the session: set the ready flags and register the setter callback.
 */
void func_02156344(void *heapId)
{
    u32 sessionSize;
    _pRapWork->vchatLocalOn = 1;
    _pRapWork->vchatPeerOn = 1;
    _pRapWork->vchatGateOpen = 1;
    if (_pRapWork->vchatActive == 0) {
        sessionSize = 1;
        switch (_pRapWork->vchatPlayerCount) {
        case 2:
            sessionSize = 1;
            break;
        case 3:
            sessionSize = 2;
            break;
        case 4:
            sessionSize = 3;
            break;
        case 5:
            sessionSize = 4;
            break;
        default:
            sessionSize = 4;
            break;
        }
        func_021AEF6C(heapId, sessionSize, 1);
        func_021AF18C(func_0215631C);
        _pRapWork->vchatActive = 1;
    }
}












/*
 * Halfword at +0x56 of the block func_0203D798 returns, passed on.
 */
void func_021563C0(int unused)
{
    func_02156344((void *)func_0203D798()->heapId);
}











/*
 * Asks the voice chat module to stop when it is running.
 */
void func_021563D0(void)
{
        void func_021AF13C(void);
    if (_pRapWork->vchatActive) func_021AF13C();
}










/*
 * True while the voice chat is running.
 */
int func_021563EC(void) {
 return _pRapWork->vchatActive;
}










void func_02156400(void)
{
    func_021AF1A0();
    if (_pRapWork) {
        _pRapWork->vchatActive = 0;
        _pRapWork->vchatAidBitmap = 0;
        _pRapWork->vchatLocalOn = 0;
    }
}








/*
 * Retains the live result of func_0216B838 as func_021AF2AC's argument.
 */
void func_0215642C(int lock)
{
    if (lock) {
        func_021AF2AC(func_0216B838());
        _pRapWork->vchatTalkLock = 1;
    } else {
        _pRapWork->vchatTalkLock = 0;
    }
    func_021AF30C(_pRapWork->vchatTalkLock);
}









/*
 * Classify a network error code (and its error kind) into a message class.
 */
int func_02156460(int errorCode, int errorType)
{
    int errorGroup100 = errorCode / 100;
    int errorGroup1000 = errorCode / 1000;

    if (errorCode == 20101)
        return 1;
    if (errorGroup1000 == 23)
        return 1;
    if (errorCode == 20108)
        return 2;
    if (errorCode == 20110)
        return 3;
    if (errorGroup100 == 512)
        return 4;
    if (errorGroup100 == 500)
        return 5;
    if (errorCode == 51103)
        return 6;
    if (errorGroup100 == 510)
        return 6;
    if (errorGroup100 == 511)
        return 6;
    if (errorGroup100 == 513)
        return 6;
    if (errorCode >= 52000 && errorCode <= 52003)
        return 8;
    if (errorCode >= 52010 && errorCode <= 52012)
        return 8;
    if (errorCode >= 52100 && errorCode <= 52103)
        return 8;
    if (errorCode >= 52110 && errorCode <= 52112)
        return 8;
    if (errorCode >= 52200 && errorCode <= 52203)
        return 8;
    if (errorCode >= 52210 && errorCode <= 52212)
        return 8;
    if (errorCode >= 52400 && errorCode <= 52403)
        return 8;
    if (errorCode >= 52410 && errorCode <= 52412)
        return 8;
    if (errorCode >= 52500 && errorCode <= 52503)
        return 8;
    if (errorCode >= 52510 && errorCode <= 52512)
        return 8;
    if (errorCode >= 52700 && errorCode <= 52703)
        return 8;
    if (errorCode >= 52710 && errorCode <= 52712)
        return 8;
    if (errorCode == 80430)
        return 9;
    if (errorGroup1000 == 20)
        return 0;
    if (errorGroup100 == 520)
        return 0;
    if (errorGroup100 == 521)
        return 0;
    if (errorGroup100 == 522)
        return 0;
    if (errorGroup100 == 523)
        return 0;
    if (errorGroup100 == 530)
        return 0;
    if (errorGroup100 == 531)
        return 0;
    if (errorGroup100 == 532)
        return 0;
    if (errorCode < 10000)
        return 14;
    if (errorGroup1000 == 31)
        return 12;
    switch (errorType) {
    case 0:
    case 1:
        return 14;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return 11;
    default:
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
        break;
    case 7:
        return 15;
    }
    return -1;
}









int func_02156690(int pollOnly)
{
    u32 errorCode, errorType;
    if (func_02059E38((int *)(&errorCode), (int *)(&errorType)) != 0) {
        func_02059F18();
    }
    if (pollOnly == 0) {
        switch (_pRapWork->state) {
        case DWC_RAP_STATE_MATCHING:
        case DWC_RAP_STATE_CONNECTED:
        case DWC_RAP_STATE_IN_SESSION:
            if (_pRapWork->vchatActive != 0) {
                func_021AF13C();
            }
            func_02155374(DWC_RAP_STATE_CLOSING);
            break;
        case DWC_RAP_STATE_IDLE:
        case DWC_RAP_STATE_FATAL_DISCONNECT:
        case DWC_RAP_STATE_CLOSED:
        case DWC_RAP_STATE_TIMED_OUT:
            return 1;
        default:
            break;
        }
    } else {
        switch (_pRapWork->state) {
        case DWC_RAP_STATE_IDLE:
        case DWC_RAP_STATE_CLOSED:
        case DWC_RAP_STATE_TIMED_OUT:
            return 1;
        default:
            break;
        }
    }
    return 0;
}









int func_02156730(void)
{
    u32 state = _pRapWork->state;
    if (state == DWC_RAP_STATE_CLOSED || state == DWC_RAP_STATE_TIMED_OUT || state == DWC_RAP_STATE_FATAL_DISCONNECT || state == DWC_RAP_STATE_IDLE) {
        u32 idleState = 6;
        func_02155374(idleState);
        _pRapWork->result = DWC_RAP_RESULT_IDLE;
        _pRapWork->newClientAid = idleState - 7;
        return 1;
    }
    return 0;
}








void func_0215677C(void)
{
    if (_pRapWork != 0) {
        func_02059F18();
        if (_pRapWork->friendsMatchInit != 0)
            func_0216AD50();
        _pRapWork->friendsMatchInit = 0;
        func_0205CC20();
        func_02156400();
        func_021554A0();
    }
}









void func_021567B8(void)
{
    if (_pRapWork->friendList != 0) {
        u32 slot = _pRapWork->friendPollCursor & 0x1f;
        u32 byteOffset = slot * 12;
        int statusLen;
        if (func_0205912C(_pRapWork->friendList + byteOffset) != 0) {
            u32 status = func_02168848(_pRapWork->friendList + byteOffset,
                                  (int)_pRapWork->friendStatusData[slot], (int)(&statusLen));
            if (statusLen < 1) {
                _pRapWork->friendStatus[slot] = 0;
                func_02082BCC(_pRapWork->friendStatusData[slot], 0, 0x20);
            } else {
                _pRapWork->friendStatus[slot] = status;
            }
        }
        _pRapWork->friendPollCursor += 1;
    }
}







int func_0215683C(char *data, int size)
{
    if (size > 32)
        func_02034714(_sAssertEmpty, 0, _sAssertEmpty);
    return func_021688FC(data, size);
}








/*
 * Status string of one friend.
 */
int func_02156860(int friendIndex)
{
    return (int)_pRapWork->friendStatusData[friendIndex];
}








/*
 * Byte at +0x32c past the index of the block the module pointer holds.
 */
unsigned char func_02156874(int friendIndex)
{
    return _pRapWork->friendStatus[friendIndex];
}








int func_02156888(int friendIndex, int maxPlayers, int limitToTwo)
{
    int entryCount = maxPlayers;
    int started;
    int slot;

    if (func_02156C84() != 0)
        return -4;
    if (_pRapWork->state != DWC_RAP_STATE_IDLE) {
        _pRapWork->peerCounter[2]++;
        if (_pRapWork->peerCounter[2] > 0x78)
            return -3;
        return -1;
    }
    func_02156C60();
    _pRapWork->aidBitmapAtConnect = 0;
    _pRapWork->connectArmed = 1;
    _pRapWork->targetFriendIndex = friendIndex;
    _pRapWork->maxPlayers = maxPlayers;
    _pRapWork->canceledPeerIndex = -1;
    if (limitToTwo != 0)
        entryCount = 2;
    _pRapWork->connectPending = 1;
    if (friendIndex < 0) {
        started = func_0216B354(2, entryCount, func_02156A58, (void *)func_0203D650(), func_02156B3C,
                          (void *)func_0203D650(), func_02155678, &_pRapWork->connectionUserData,
                          (void *)func_0203D650());
        _pRapWork->connectMode = 1;
    } else {
        started = func_0216B408(2, friendIndex, func_02156B18, 0, func_02156B3C,
                          func_0203D650(), func_02155678, &_pRapWork->connectionUserData,
                          func_0203D650());
        _pRapWork->connectMode = 2;
    }
    if (started == 0) {
        _pRapWork->peerCounter[2]++;
        if (_pRapWork->peerCounter[2] > 0x78)
            func_0203C9AC(0, 0, 0, DWC_RAP_RESULT_DISCONNECT_ERROR);
        return -2;
    }
    _pRapWork->peerCounter[2] = 0;
    for (slot = 0; slot < maxPlayers; slot++)
        func_02156C00(slot);
    func_02155374(DWC_RAP_STATE_MATCHING);
    func_02177138((int)func_02155D80, 0);
    func_02177160((int)func_02155DCC, 0);
    func_0216B634((int)func_02155E9C, 0);
    func_02177188((int)func_02155BDC, 0);
    _pRapWork->sendInFlight = 0;
    return 0;
}








int func_02156A3C(void)
{
    if (_pRapWork != 0)
        return _pRapWork->targetFriendIndex;
    return -1;
}








void func_02156A58(int error, int cancel, int self, int isServer, int peerIndex)
{
    int reject = 0;
    _pRapWork->connectPending = 0;
    if (error == 0) {
        if (cancel == 0) {
            if (_pRapWork->rejectStrangers != 0 && peerIndex == -1) {
                reject = 1;
            }
            if (_pRapWork->acceptFriendFunc != 0) {
                if (_pRapWork->acceptFriendFunc(peerIndex, func_0203D650()) == 0) {
                    reject = 1;
                }
            }
            if (_pRapWork->kickNewPeers != 0 || reject != 0) {
                if (peerIndex != -1) {
                    func_0216B7E0(peerIndex);
                }
            }
            _pRapWork->targetFriendIndex = peerIndex;
            _pRapWork->aidBitmapAtConnect = func_0216B908();
            if (_pRapWork->aidBitmapAtConnect == 1) {
                func_02155374(DWC_RAP_STATE_CANCELING);
                return;
            }
            func_02155D2C(peerIndex);
            return;
        }
        if (self == 0) {
            _pRapWork->canceledPeerIndex = peerIndex;
            _pRapWork->newClientAid = reject - 1;
        }
    }
}







/*
 * The fifth input is visibly loaded into r0 before the call.
 */
void func_02156B18(int error, int cancel, int self, int isServer, int peerIndex)
{
    _pRapWork->connectPending = 0;
    if (error == 0 && cancel == 0)
        func_02155D2C(peerIndex);
}







/*
 * New client callback of the host match: remembers the AID and tells the game.
 */
void func_02156B3C(int aid)
{
    _pRapWork->newClientAid = aid;
    if (_pRapWork->connectEventFunc != 0)
        _pRapWork->connectEventFunc((u16)aid, _pRapWork->connectEventArg);
}







/*
 * Voice chat state query of the ov013 module (the argument is not used).
 */
int func_02156B68(char *unused)
{
    return func_021AF210();
}








/*
 * Voice chat enabled flag, 0 when no work block exists.
 */
s16 func_02156B70(void)
{
    if (_pRapWork != 0)
        return _pRapWork->vchatEnabled;
    return 0;
}








/*
 * Word at +0x774 of the work block, or 0 when none is allocated.
 */
int func_02156B8C(void)
{
    if (_pRapWork != 0)
        return _pRapWork->newClientAid;
    return 0;
}









/*
 * Index of the peer that cancelled the match, -1 when none.
 */
int func_02156BA8(void)
{
    if (_pRapWork)
        return _pRapWork->canceledPeerIndex;
    return -1;
}










/*
 * Sets the voice chat enabled flag.
 */
void func_02156BC4(int enabled)
{
    _pRapWork->vchatEnabled = enabled;
}








void func_02156BD8(u32 aid)
{
    void *buf;
    buf = _pRapWork->recvBuffer[aid];
    if (buf != 0) {
        func_0203D7FC(buf);
        _pRapWork->recvBuffer[aid] = 0;
    }
}








void func_02156C00(u32 aid)
{
    DwcRapNetInit *netInit = func_0203D798();
    func_02156BD8(aid);
    if (_pRapWork->recvBuffer[aid] == 0) {
        u32 bufSize = 0x1000;
        _pRapWork->recvBuffer[aid] =
            func_0203D7C8(netInit->heapId, bufSize, (const char *)_sDwcRapFile, 0xb74);
        func_021770EC(aid, (u32)_pRapWork->recvBuffer[aid], bufSize);
    }
}








/*
 * Resets the two slots and marks the flag at +0x7a6.
 */
void func_02156C60(void)
{
    int aid;

    for (aid = 0; aid < 2; aid++) {
        func_02156BD8(aid);
    }

    _pRapWork->sendStateReady = 1;
}









/*
 * Byte at +0x7a2 of the block the module pointer holds.
 */
unsigned char func_02156C84(void)
{
    return _pRapWork->userDataChanged;
}








/*
 * Clears the user data changed flag (the argument is not used).
 */
void func_02156C98(int unused) { _pRapWork->userDataChanged = 0; }








int func_02156CAC(void)
{
    if (_pRapWork) {
        if (_pRapWork->state == DWC_RAP_STATE_IDLE) return 1;
        return 0;
    }
    return 0;
}







/*
 * True in the connected and in-session states.
 */
int func_02156CD0(void)
{

    if (_pRapWork != 0) {
        if ((u32)(_pRapWork->state - 9) <= 1)
            return 1;
    }
    return 0;
}





void func_02156CF4(void)
{
    int slot;

    for (slot = 0; slot < 32; slot++) {
        if (_pRapWork->deletedFriendIndex[slot] != -1) {
            DwcRapNetInit *netInit = func_0203D798();
            if (netInit->deleteFriendFunc != 0) {
                DwcRapWork *entry = (DwcRapWork *)((int *)_pRapWork + slot);
                u32 userArg = func_0203D650();
                netInit->deleteFriendFunc(entry->deletedFriendIndex[0], entry->deletedFriendSrcIndex[0], userArg);
            }
            _pRapWork->deletedFriendIndex[slot] = -1;
        }
    }
}





u32 func_02156D5C(void)
{
    return _pRapWork->result;
}





void func_02156D70(u32 allowed)
{
    _pRapWork->allowConnect = allowed;
}





/*
 * Two functions: 0x02156D84, 0x02156DB0.
 */
int func_02156D84(void)
{
    DwcRapWork *work = _pRapWork;
    if (work == 0) {
        return 1;
    }
    {
        u32 state = work->state;
        if (state == DWC_RAP_STATE_CLOSED || state == DWC_RAP_STATE_FATAL_DISCONNECT || state == DWC_RAP_STATE_TIMED_OUT) {
            return 1;
        }
    }
    return 0;
}





void func_02156DB0(u32 enabled)
{
    _pRapWork->errorOnDisconnect = enabled;
}









/*
 * Sets the error callback and its argument.
 */
void func_02156DC4(int (*errorFunc)(u32, u32, u32, int), u32 errorArg)
{
    _pRapWork->errorFunc = errorFunc;
    _pRapWork->errorArg = errorArg;
}








/*
 * Sets the error hook callback and its argument; the hook runs before the error callback.
 */
void func_02156DE0(int (*hookFunc)(u32, u32, u32, int), u32 hookArg)
{
    _pRapWork->errorHookFunc = hookFunc;
    _pRapWork->errorHookArg = hookArg;
}









/*
 * Initialises the DWC library; when it reports that other settings were
 * destroyed (result 3) the notice screen of overlay 17 runs (the pooled 0x11
 * is the overlay id).
 */
void func_02156DFC(int heapId)
{
    if (func_02157108(heapId) == 3) {
        func_02034AC4((int)abs_id_11);
        func_021B6100();
        func_02034A5C((int)abs_id_11);
    }
}








/*
 * Calls func_02156E30 with a zero third argument.
 */
void func_02156E24(int ownerId, int size, int heapId)
{
    func_02156E30(ownerId, size, 0, heapId);
}







/*
 * Creates the secondary expanded heap that serves allocations of one owner id
 * (ownerId) above minRequestSize; the heap is tagged 0xEA so that the free
 * function can tell its blocks from the main heap blocks.
 */
void func_02156E30(u32 ownerId, u32 size, u32 minRequestSize, u32 heapId)
{
    if (_pRapHeap == 0) {
        func_02034714(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->subMem != 0) {
        func_02034714(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->subHeap != 0) {
        func_02034714(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    _pRapHeap->subMem = (u32)func_02030734(heapId, size - 0x80, 0, _sDwcRapCommonFile, 0x62);
    _pRapHeap->subHeap = (u32)func_02060C5C((void *)((_pRapHeap->subMem + 0x1f) & ~0x1f), size - 0xc0, 0);
    _pRapHeap->subOwnerId = ownerId;
    func_02060F18((char *)_pRapHeap->subHeap, 1);
    func_02060F40((char *)_pRapHeap->subHeap, 0xea);
    _pRapHeap->subMinRequest = minRequestSize;
}






void func_02156ED0(void)
{
    if (_pRapHeap == 0) {
        func_02034714(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->subLiveBlocks != 0) {
        func_0203C9AC(0, 0, 0, DWC_RAP_RESULT_FATAL);
        _pRapHeap->allocFailed = 1;
        return;
    }
    func_02156F14();
}





void func_02156F14(void)
{
    if (_pRapHeap->subMem != 0) {
        func_02060C94((void *)_pRapHeap->subHeap);
        func_020307B0((void *)_pRapHeap->subMem);
        _pRapHeap->subHeap = 0;
        _pRapHeap->subMem = 0;
        if (_pRapHeap->tag != 0) {
            func_020306F0(_pRapHeap->tag);
            _pRapHeap->tag = 0;
        }
    }
}






/*
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object _pRapHeap
 * points to. Called from the ov175 root func_021D7E18 (0x021D85E0).
 */
void func_02156F50(int tag)
{
    _pRapHeap->tag = tag;
}






u32 func_02156F5C(u32 ownerId, u32 size, u32 align)
{
    u32 irqState;
    u32 block;

    if (_pRapHeap->subHeap != 0 && ownerId == _pRapHeap->subOwnerId && size > _pRapHeap->subMinRequest) {
        irqState = func_02087988();
        block = (u32)func_02060CA0((struct ExpHeap *)_pRapHeap->subHeap, size, align);
        func_0208799C(irqState);
        _pRapHeap->subLiveBlocks++;
    } else {
        irqState = func_02087988();
        block = (u32)func_02060CA0((struct ExpHeap *)_pRapHeap->mainHeap, size, align);
        func_0208799C(irqState);
    }
    if (block == 0) {
        func_0200FB6C();
        func_0203C9AC(0, 0, 0, DWC_RAP_RESULT_FATAL);
        return 0;
    }
    return block;
}




/*
 * witness:  callee 0x02060F98 is witnessed by its ARM9 entry
 *           (src/matched/arm9/func_02060F98.c, pkt_02060F98).
 */
void func_02156FDC(u32 ownerId, void *block, int unused)
{
    u32 irqState;

    if (block == 0) {
        return;
    }
    if (func_02060F98(block) == 0xEA) {
        if (_pRapHeap->subHeap != 0) {
            irqState = func_02087988();
            func_02060E30((struct ExpHeap *)_pRapHeap->subHeap, block);
            func_0208799C(irqState);
            _pRapHeap->subLiveBlocks--;
            return;
        }
        func_0203C9AC(0, 0, 0, DWC_RAP_RESULT_FATAL);
        return;
    }
    irqState = func_02087988();
    func_02060E30((struct ExpHeap *)_pRapHeap->mainHeap, block);
    func_0208799C(irqState);
}




void func_02157048(u32 heapId, u32 size)
{
    if (_pRapHeap != 0) {
        func_02034714(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    _pRapHeap = (DwcRapHeap *)func_02030734(0, 0x24, 1, _sDwcRapCommonFile, 0x14C);
    _pRapHeap->mainMem = (u32)func_02030734(heapId, size - 0x80, 0, _sDwcRapCommonFile, 0x14D);
    _pRapHeap->mainHeap = (u32)func_02060C5C((void *)((_pRapHeap->mainMem + 0x1f) & ~0x1f), size - 0xc0, 0);
    _pRapHeap->tag = 0;
}




void func_021570B8(void)
{
    if (_pRapHeap == 0) {
        func_02034714(_sAssertEmptyCommon, 0, _sAssertEmptyCommon);
    }
    if (_pRapHeap->allocFailed == 1 || _pRapHeap->subMem != 0) {
        func_02156F14();
    }
    func_02060C94((void *)_pRapHeap->mainHeap);
    func_020307B0((void *)_pRapHeap->mainMem);
    func_020307B0(_pRapHeap);
    _pRapHeap = 0;
}



int func_02157108(u16 heapId)
{
    int initResult;
    func_02157048(heapId, 0x40000);
    initResult = func_02059F6C(_sDwcGameName, 0x4952414A, func_02156F5C, func_02156FDC);
    func_021570B8();
    return initResult;
}




/*
 * Clears the 0x40-byte DWC account user-data block, then rebuilds it when
 * the check at func_02059718 (CRC validation) fails: DWC_CreateUserData,
 * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (func_0205987C).
 * Called from arm9 sub_02009800 (bl at 0x0200982C), the save-table
 * constructor at 0x0209DB98.
 */
void func_02157138(void *userData)
{
    MIi_CpuClearFast(0, userData, 0x40);
    if (func_02059718(userData) == 0) {
        DWC_CreateUserData(userData);
        func_02059870((int)userData);
    }
}



void func_02157160(void)
{
    func_0203CA04();
    func_0203C968();
    func_02059F18();
}




/*
 * Decides what the error screen does after a network error: returns 0 for
 * nothing, 1 reset and show the connection lost screen, 2 show the message,
 * 3 show the special message, 4 reset and return to the title.
 */
int func_02157170(int hasSession, int keepError)
{
    DwcRapErrorInfo *errorInfo;
    int gameCode;

    if (func_0203CD98() != 0) {
        errorInfo = (DwcRapErrorInfo *)func_0203CA98();
        if (func_0200FB24() != 0) {
            switch (errorInfo->errorType) {
            case 0:
                break;
            case 1:
            case 2:
                if (hasSession == 0) {
                    func_02157160();
                    func_0200F83C();
                    func_0200FBA0();
                    return 1;
                }
                func_02059F18();
            case 3:
            case 4:
            case 5:
                func_0200FB38();
                func_0200FB4C(13);
                return 2;
            case 6:
                func_0200FB38();
                return 2;
            case 7:
                func_0200F7C0(15);
                return 3;
            }
        }
        gameCode = errorInfo->gameCode;
        if (gameCode == DWC_RAP_RESULT_TIMEOUT_ERROR || gameCode == DWC_RAP_RESULT_DISCONNECT_ERROR) {
            if (keepError != 0) {
                func_0200FAAC();
                func_02157160();
                func_0203C554(1);
                func_0200F83C();
                func_0200FBA0();
                return 4;
            }
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            func_0203C554(1);
            return 0;
        }
        if (gameCode == 0x3F2 || gameCode == 0x3F3 || gameCode == 0x3F4 || gameCode == 0x3F6) {
            if (hasSession == 0) {
                func_02157160();
                func_0200F83C();
                func_0200FBA0();
                return 1;
            }
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
        if (gameCode == DWC_RAP_RESULT_FATAL || gameCode == 0x3F7) {
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
    }
    return 0;
}
