/*
 * file:     unit_021DDB38.c
 * unit:     yes
 * function: func_021DDB38, func_021DDBE4, func_021DDF74, func_021DDFBC, func_021DDFF8, func_021DE024, func_021DE038, func_021DE078, func_021DE0D4, func_021DE0E8, func_021DE100
 * address:  0x021DDB38
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sakeiValidateRequestFields  0x021DDB38  arm
 *   g_021E3A8C  0x021E3A8C  data
 *   g_021E3A90  0x021E3A90  data
 *   g_021E3A98  0x021E3A98  data
 *   g_021E3AA4  0x021E3AA4  data
 *   g_021E3AAC  0x021E3AAC  data
 *   g_021E3AB4  0x021E3AB4  data
 *   g_021E3AC0  0x021E3AC0  data
 *   g_021E3ACC  0x021E3ACC  data
 *   g_021E3AD8  0x021E3AD8  data
 *   g_021E3AE4  0x021E3AE4  data
 *   g_021E3AF0  0x021E3AF0  data
 *   g_021E3B04  0x021E3B04  data
 *   g_021E3B18  0x021E3B18  data
 *   g_021E3B28  0x021E3B28  data
 *   g_021E3B3C  0x021E3B3C  data
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_02182AC0  0x02182AC0  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02182D78  0x02182D78  arm  ov009
 *   func_02182DFC  0x02182DFC  arm  ov009
 *   func_02182C10  0x02182C10  arm  ov009
 *   func_02182FF8  0x02182FF8  arm  ov009
 *   func_02182F40  0x02182F40  arm  ov009
 *   func_02182A2C  0x02182A2C  arm  ov009
 *   g_021E3B4C      0x021E3B4C  data
 *   func_02183A24  0x02183A24  arm
 *   g_021E3B54     0x021E3B54  data
 *   d_021E39A0  0x021E39A0  data
 *   d_021E3978  0x021E3978  data
 */
struct SAKEField;
struct SAKERequestInternal;
typedef struct {
    char *name;
    int type;
    void *p;
    int len;
} ReqField;

typedef struct SAKEBinaryData {
    unsigned char *mValue;
    int mLength;
} SAKEBinaryData;

typedef union SAKEValue {
    unsigned char mByte;
    short mShort;
    int mInt;
    long long mInt64;
    float mFloat;
    char *mAsciiString;
    unsigned short *mUnicodeString;
    int mBoolean;
    long mDateAndTime;
    SAKEBinaryData mBinaryData;
} SAKEValue;

typedef struct SAKEField {
    char *mName;
    int mType;
    SAKEValue mValue;
} SAKEField;

typedef struct SAKERequestInternal {
    void *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    void *mCallback;
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    void *mInfo;
} SAKERequestInternal;

typedef int s32;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Blk;

extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182D78(void *stream, char *namespaceName, char *tag, long long value);
extern int func_02182DFC(void *stream, char *namespaceName, char *tag, float value);
extern int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value);
extern int func_02182FF8(void *stream, char *namespaceName, char *tag, long value);
extern int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02183A24(u32, u32 *, u32);
extern int func_021DDB10(void *, int);
int func_021DDB38(ReqField *req, int count);
void func_021DDBE4(SAKERequestInternal *request, SAKEField *fields, int numFields);
s32 func_021DDF74(char *p);
u32 func_021DDFBC(char *obj);
int func_021DDFF8(char *p);
int func_021DE024(void *p);
int func_021DE038(char *p);
int func_021DE078(int *p);
int func_021DE0D4(void *p);
int func_021DE0E8(void *p);
int func_021DE100(char *p);
extern char g_021E3A8C[];
extern char g_021E3A90[];
extern char g_021E3A98[];
extern char g_021E3AA4[];
extern char g_021E3AAC[];
extern char g_021E3AB4[];
extern char g_021E3AC0[];
extern char g_021E3ACC[];
extern char g_021E3AD8[];
extern char g_021E3AE4[];
extern char g_021E3AF0[];
extern char g_021E3B04[];
extern char g_021E3B18[];
extern char g_021E3B28[];
extern char g_021E3B3C[];
extern u32 g_021E3B4C[];
extern u32 g_021E3B54[];
extern char d_021E39A0[];
extern char d_021E3978[];


int func_021DDB38(ReqField *req, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (req[i].name == 0 || *req[i].name == 0)
            return 7;
        if (req[i].type >= 10)
            return 8;
        if (req[i].type == 4 && req[i].p == 0)
            return 9;
        if (req[i].type == 5 && req[i].p == 0)
            return 9;
        if (req[i].type == 8) {
            if (req[i].len < 0)
                return 9;
            if (req[i].p == 0 && req[i].len > 0)
                return 9;
        }
    }
    return 0;
}





void func_021DDBE4(SAKERequestInternal *request, SAKEField *fields, int numFields)
{
    int i;

    func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3A90);
    for (i = 0; i < numFields; i++) {
        func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3A98);
        func_02182AC0(request->mSoapRequest, g_021E3A8C, g_021E3AA4, fields[i].mName);
        func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AAC);
        if (fields[i].mType == 0) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AB4);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mByte);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AB4);
        } else if (fields[i].mType == 1) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AC0);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mShort);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AC0);
        } else if (fields[i].mType == 2) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3ACC);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mInt);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3ACC);
        } else if (fields[i].mType == 9) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AD8);
            func_02182D78(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mInt64);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AD8);
        } else if (fields[i].mType == 3) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AE4);
            func_02182DFC(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mFloat);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AE4);
        } else if (fields[i].mType == 4) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AF0);
            func_02182AC0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mAsciiString);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AF0);
        } else if (fields[i].mType == 5) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B04);
            func_02182C10(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mUnicodeString);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B04);
        } else if (fields[i].mType == 6) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B18);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mBoolean ? 1 : 0);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B18);
        } else if (fields[i].mType == 7) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B28);
            func_02182FF8(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mDateAndTime);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B28);
        } else if (fields[i].mType == 8) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B3C);
            func_02182F40(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mBinaryData.mValue, fields[i].mValue.mBinaryData.mLength);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B3C);
        }
        func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AAC);
        func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3A98);
    }
    func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3A90);
}






s32 func_021DDF74(char *p)
{
    s32 *q = *(s32 **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[2] < 0)
        return 6;
    if (q[1] == 0) {
        if (q[2] > 0)
            return 5;
    }
    return func_021DDB38((ReqField *)q[1], q[2]);
}






u32 func_021DDFBC(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    func_02182AC0((void *)(*(u32 *)(obj + 0x18)), (char *)((u32)g_021E3A8C), (char *)((u32)g_021E3B4C), (char *)b->f0);
    func_021DDBE4((SAKERequestInternal *)((struct SAKERequestInternal *)((u32)obj)), (SAKEField *)((struct SAKEField *)b->f4), b->f8);
    return 0;
}






/*
 * Hand the +0x1c handle, the shared 0x021E3B54 descriptor and the +0x0c value
 * to func_02183A24; a refusal (0) is reported as 5.
 */
int func_021DDFF8(char *p)
{
    return func_02183A24(*(u32 *)(p + 0x1c), g_021E3B54, *(u32 *)(p + 0xc)) == 0 ? 5 : 0;
}





int func_021DE024(void *p)
{
    return func_021DDB10(p, (int)d_021E39A0);
}





/*
 * Pre-flight check of the +0x08 block: a missing head or an empty count is
 * rejected with 4, a non-positive count with 6, a missing name table with 5;
 * otherwise the table is checked word by word by func_021DDB38.
 */
int func_021DE038(char *p)
{
    int *q = *(int **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[3] <= 0)
        return 6;
    if (q[2] == 0)
        return 5;
    return func_021DDB38((ReqField *)((s32)((char **)q[2])), q[3]);
}





/*
 * note:     the listing extent (136 B) runs past this 92-byte body into the
 *           next function's leaf and pool words; every compiled byte matches.
 *
 * Object teardown: the object's +8 table supplies the two title strings that
 * get unregistered from the shared group, then the object's own four table
 * words go back to the pool manager.
 */
int func_021DE078(int *p)
{
    int *q = (int *)p[2];

    func_02182AC0((void *)p[6], (char *)((int)g_021E3A8C), (char *)((int)g_021E3B4C), (char *)q[0]);
    func_02182CF0((void *)p[6], (char *)((int)g_021E3A8C), (char *)((int)g_021E3B54), q[1]);
    func_021DDBE4((SAKERequestInternal *)((struct SAKERequestInternal *)p), (SAKEField *)((struct SAKEField *)q[2]), q[3]);
    return 0;
}




/*
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder to func_021DDB10 with a fixed second argument.
 */
int func_021DE0D4(void *p)
{
    return func_021DDB10(p, (int)d_021E3978);
}




/*
 * SDK provenance: sakeiDeleteRecordValidateInput (TwlDWC/libdwcgssake.TWL.HYB.a,
 * sakerequestmodif.o), ov175.  A null record reads as the "out of range" 4,
 * a live record as 0.
 */
int func_021DE0E8(void *p)
{
    return *(u32 *)(*(u32 *)((char *)p + 8)) != 0 ? 0 : 4;
}




/*
 * Forward the +0x08 block's first two words to the two ov009 record readers,
 * both keyed on the +0x18 handle.
 */
int func_021DE100(char *p)
{
    u32 *q = *(u32 **)(p + 8);

    func_02182AC0((void *)(*(u32 *)(p + 0x18)), (char *)g_021E3A8C, (char *)g_021E3B4C, (char *)q[0]);
    func_02182CF0((void *)(*(u32 *)(p + 0x18)), (char *)g_021E3A8C, (char *)g_021E3B54, q[1]);
    return 0;
}
