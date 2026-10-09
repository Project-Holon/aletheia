/*
 * file:     unit_021DE14C.c
 * unit:     yes
 * function: func_021DE14C, func_021DE184, func_021DE1F8, func_021DE26C, sakeiReadOutputRecords, func_021DE840, func_021DE8AC, func_021DE95C, func_021DE9BC, func_021DEAD4, func_021DEAF8, func_021DEB1C, func_021DEB5C, func_021DEB98, func_021DEBBC, func_021DEBE0, func_021DEBF4, func_021DEC54, func_021DECA0, func_021DECC4, func_021DECE8, func_021DECFC, func_021DED3C, func_021DEDB4, func_021DEE18
 * address:  0x021DE14C
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
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3DFC     0x021E3DFC  data
 *   d_021E3E04     0x021E3E04  data
 *   func_021829AC  0x021829AC  arm
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182A2C  0x02182A2C  arm
 *   d_021E3E0C     0x021E3E0C  data
 *   d_021E3E18     0x021E3E18  data
 *   func_02182CF0  0x02182CF0  arm
 *   d_021E3E1C     0x021E3E1C  data
 *   gsXmlMoveToChild              0x021835D0 arm ov009
 *   gsXmlCountChildren            0x02183EE0 arm ov009
 *   gsimalloc                     0x0217EAB0 arm ov009
 *   memset                        0x020923B0 arm
 *   gsXmlMoveToNext               0x021834E8 arm ov009
 *   gsXmlReadChildAsInt           0x02183A24 arm ov009
 *   gsXmlReadChildAsInt64         0x02183AE4 arm ov009
 *   gsXmlReadChildAsFloat         0x02183CD4 arm ov009
 *   gsXmlReadChildAsString        0x02183670 arm ov009
 *   UTF8ToUCS2StringAlloc         0x021802C8 arm ov009
 *   strcmp                        0x020948E0 arm
 *   gsXmlReadChildAsDateTimeElement 0x02183BA4 arm ov009
 *   gsXmlReadChildAsBase64Binary  0x02183918 arm ov009
 *   gsifree                       0x0217EAE0 arm ov009
 *   g_021E3E28                    0x021E3E28 data ov175
 *   g_021E3E30                    0x021E3E30 data ov175
 *   g_021E3E44                    0x021E3E44 data ov175
 *   g_021E3E50                    0x021E3E50 data ov175
 *   g_021E3E5C                    0x021E3E5C data ov175
 *   g_021E3E64                    0x021E3E64 data ov175
 *   g_021E3E70                    0x021E3E70 data ov175
 *   g_021E3E7C                    0x021E3E7C data ov175
 *   g_021E3E88                    0x021E3E88 data ov175
 *   g_021E3E94                    0x021E3E94 data ov175
 *   g_021E3EA8                    0x021E3EA8 data ov175
 *   g_021E3EAC                    0x021E3EAC data ov175
 *   g_021E3EC0                    0x021E3EC0 data ov175
 *   g_021E3ED0                    0x021E3ED0 data ov175
 *   g_021E3ED8                    0x021E3ED8 data ov175
 *   g_021E3EEC                    0x021E3EEC data ov175
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   d_021E3EFC      0x021E3EFC  data  ov175
 *   d_021E3F04      0x021E3F04  data  a4
 *   d_021E3F0C      0x021E3F0C  data  ov175
 *   d_021E3F14      0x021E3F14  data  ov175
 *   d_021E3F1C      0x021E3F1C  data  ov175
 *   d_021E3F20      0x021E3F20  data  ov175
 *   d_021E3F30      0x021E3F30  data  ov175
 *   d_021E3F3C      0x021E3F3C  data  ov175
 *   g_021E3DF8      0x021E3DF8  data
 *   g_021E3EFC      0x021E3EFC  data
 *   d_021E3CA0  0x021E3CA0  data
 *   func_021DE2E0  0x021DE2E0  arm
 *   d_021E3C78  0x021E3C78  data
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct SAKEField {
    char *name;
    int type;
    union {
        u8 byte;
        u16 sshort;
        int ival;
        float fval;
        char *str;
        unsigned short *ustr;
        long long i64;
        struct {
            unsigned char *ptr;
            int len;
        } binary;
        int bval;
        long date;
    } value;
} SAKEField;

typedef struct SAKERequestInternal {
    char pad0[0x1c];
    void *stream;
} SAKERequestInternal;

typedef struct {
    int f0;
    int type;
    void *p8;
    int f12;
} Ent;

typedef unsigned int u32_021DE95C;

typedef struct S {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
} S;

typedef struct O {
    char _0[8];
    S *f8;
    char _c[0x18 - 0xc];
    void *f18;
} O;

typedef unsigned long u32_021DEAD4;

typedef unsigned int u32_021DEB5C;

typedef struct {
    u32_021DEB5C f0;
    u32_021DEB5C f4;
    u32_021DEB5C f8;
} Blk;

typedef unsigned long u32_021DEB98;

typedef unsigned int u32_021DEBF4;

typedef unsigned int u32_021DEC54;

typedef unsigned int u32_021DECFC;

extern void func_021829AC(void *, void *, void *);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_02182A2C(void *, void *, void *);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlMoveToChild(void *stream, char *matchtag);
extern int gsXmlCountChildren(void *stream, char *matchtag);
extern void *gsimalloc(unsigned long size);
extern void memset(void *dst, int val, unsigned long n);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlReadChildAsInt64(void *stream, char *matchtag, long long *valueOut);
extern int gsXmlReadChildAsFloat(void *stream, char *matchtag, float *valueOut);
extern int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut);
extern unsigned short *UTF8ToUCS2StringAlloc(char *theUTF8String);
extern int strcmp(const char *a, const char *b);
extern int gsXmlReadChildAsDateTimeElement(void *stream, char *matchtag, long *valueOut);
extern int gsXmlReadChildAsBase64Binary(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut);
extern void gsifree(void *ptr);
extern void func_0217EAE0(void *ptr);
extern int func_021DE2E0(u32_021DEAD4 a, u32_021DEAD4 b, u32_021DEAD4 c, u32_021DEAD4 d, u32_021DEAD4 e);
extern int func_021DDB10(void *, int);
int func_021DE14C(char **names, int n);
void func_021DE184(u32 ctx, u32 *arr, int n);
void func_021DE1F8(u32 ctx, u32 *arr, int n);
void func_021DE26C(u32 ctx, u32 *arr, int n);
void func_021DE840(int numFields, SAKEField *record);
void func_021DE8AC(int a, int b, Ent **arr);
int func_021DE95C(u32_021DE95C ctx);
int func_021DE9BC(O *o);
void func_021DEAD4(char *obj);
void func_021DEAF8(char *obj);
int func_021DEB1C(char *p);
u32_021DEB5C func_021DEB5C(char *obj);
void func_021DEB98(char *obj);
void func_021DEBBC(char *p);
int func_021DEBE0(void *p);
int func_021DEBF4(u32_021DEBF4 ctx);
int func_021DEC54(u32_021DEC54 ctx);
void func_021DECA0(char *obj);
void func_021DECC4(char *p);
int func_021DECE8(void *p);
int func_021DECFC(u32_021DECFC ctx);
int func_021DED3C(u32_021DECFC ctx);
int func_021DEDB4(int **p);
void func_021DEE18(char *p);
extern char d_021E3DF8[];
extern char d_021E3DFC[];
extern char d_021E3E04[];
extern char d_021E3E0C[];
extern char d_021E3E18[];
extern char d_021E3E1C[];
extern char g_021E3E28[];
extern char g_021E3E30[];
extern char g_021E3E44[];
extern char g_021E3E50[];
extern char g_021E3E5C[];
extern char g_021E3E64[];
extern char g_021E3E70[];
extern char g_021E3E7C[];
extern char g_021E3E88[];
extern char g_021E3E94[];
extern char g_021E3EA8[];
extern char g_021E3EAC[];
extern char g_021E3EC0[];
extern char g_021E3ED0[];
extern char g_021E3ED8[];
extern char g_021E3EEC[];
extern char d_021E3EFC[];
extern char d_021E3F04[];
extern char d_021E3F0C[];
extern char d_021E3F14[];
extern char d_021E3F1C[];
extern char d_021E3F20[];
extern char d_021E3F30[];
extern char d_021E3F3C[];
extern u32_021DEB5C g_021E3DF8[];
extern u32_021DEB5C g_021E3EFC[];
extern char d_021E3CA0[];
extern char d_021E3C78[];




/*
 * ARM leaf scan over an array of string pointers: returns 7 as soon as it
 *     meets an entry with no string or an empty one, and 0 when all `n` entries
 *     carry text.  Used to reject a table of names with a hole in it.
 */
int func_021DE14C(char **names, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        char *s = names[i];

        if (s == 0 || *s == 0)
            return 7;
    }
    return 0;
}





/*
 * SDK provenance: sakeiFillSoapRequestFieldNames
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Open the field
 * list, add one formatted element per name, then close it.
 */
void func_021DE184(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3DFC);
    for (i = 0; i < n; i++)
        func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E04,
                      (void *)arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3DFC);
}





void func_021DE1F8(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E0C);
    for (i = 0; i < n; i++)
        func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E18,
                      arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E0C);
}




void func_021DE26C(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E1C);
    for (i = 0; i < n; i++)
        func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E18,
                      arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E1C);
}



static int sakeiReadOutputRecords(SAKERequestInternal *request,
                                  SAKEField ***outputRecordsPtr, int *numRecords,
                                  int numFields, char **fieldNames)
{
    SAKEField **outputRecords;
    SAKEField *outputRecord;
    SAKEField *outputField;
    int fieldIndex;
    int recordIndex;
    unsigned long size;

    if (!gsXmlMoveToChild(request->stream, g_021E3E28))
        return 5;

    *numRecords = gsXmlCountChildren(request->stream, g_021E3E30);
    if (*numRecords == 0) {
        *outputRecordsPtr = 0;
        return 0;
    }

    size = *numRecords * 4;
    outputRecords = (SAKEField **)gsimalloc(size);
    if (outputRecords == 0)
        return 6;
    memset(outputRecords, 0, size);
    *outputRecordsPtr = outputRecords;

    for (recordIndex = 0; recordIndex < *numRecords; recordIndex++) {
        size = numFields << 4;
        {
            if (!gsXmlMoveToNext(request->stream, g_021E3E30))
                return 5;

            outputRecord = (SAKEField *)gsimalloc(size);
            if (outputRecord == 0)
                return 6;
            memset(outputRecord, 0, size);
            outputRecords[recordIndex] = outputRecord;

            if (gsXmlCountChildren(request->stream, g_021E3E44) != numFields)
                return 5;

            for (fieldIndex = 0; fieldIndex < numFields; fieldIndex++) {
                outputField = &outputRecord[fieldIndex];
                outputField->name = fieldNames[fieldIndex];
                if (!gsXmlMoveToNext(request->stream, g_021E3E44))
                    return 5;

                if (gsXmlMoveToChild(request->stream, g_021E3E50)) {
                    int value;
                    if (!gsXmlReadChildAsInt(request->stream, g_021E3E5C, &value))
                        return 5;
                    outputField->type = 0;
                    outputField->value.byte = (u8)value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3E64)) {
                    int value;
                    if (!gsXmlReadChildAsInt(request->stream, g_021E3E5C, &value))
                        return 5;
                    outputField->type = 1;
                    outputField->value.sshort = (u16)value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3E70)) {
                    int value;
                    if (!gsXmlReadChildAsInt(request->stream, g_021E3E5C, &value))
                        return 5;
                    outputField->type = 2;
                    outputField->value.ival = value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3E7C)) {
                    long long value;
                    if (!gsXmlReadChildAsInt64(request->stream, g_021E3E5C, &value))
                        return 5;
                    outputField->type = 9;
                    outputField->value.i64 = value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3E88)) {
                    float value;
                    if (!gsXmlReadChildAsFloat(request->stream, g_021E3E5C, &value))
                        return 5;
                    outputField->type = 3;
                    outputField->value.fval = value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3E94)) {
                    char *value;
                    int len;
                    if (!gsXmlReadChildAsString(request->stream, g_021E3E5C, &value, &len))
                        return 5;
                    if (value != 0)
                        value[len] = 0;
                    else
                        value = g_021E3EA8;
                    outputField->type = 4;
                    outputField->value.str = value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3EAC)) {
                    char *value;
                    int len;
                    unsigned short *valueUnicode;
                    if (!gsXmlReadChildAsString(request->stream, g_021E3E5C, &value, &len))
                        return 5;
                    if (value != 0)
                        value[len] = 0;
                    else
                        value = g_021E3EA8;
                    valueUnicode = UTF8ToUCS2StringAlloc(value);
                    if (valueUnicode == 0)
                        return 6;
                    outputField->type = 5;
                    outputField->value.ustr = valueUnicode;
                } else if (gsXmlMoveToChild(request->stream, g_021E3EC0)) {
                    char *value;
                    int len;
                    int boolval;
                    if (!gsXmlReadChildAsString(request->stream, g_021E3E5C, &value, &len))
                        return 5;
                    if (value != 0) {
                        value[len] = 0;
                        boolval = (strcmp(value, g_021E3ED0) == 0);
                    } else {
                        boolval = 0;
                    }
                    outputField->type = 6;
                    outputField->value.bval = boolval;
                } else if (gsXmlMoveToChild(request->stream, g_021E3ED8)) {
                    long value;
                    if (!gsXmlReadChildAsDateTimeElement(request->stream, g_021E3E5C, &value))
                        return 5;
                    outputField->type = 7;
                    outputField->value.date = value;
                } else if (gsXmlMoveToChild(request->stream, g_021E3EEC)) {
                    unsigned char *value;
                    int len;
                    if (!gsXmlReadChildAsBase64Binary(request->stream, g_021E3E5C, 0, &len))
                        return 5;
                    if (len > 0) {
                        value = (unsigned char *)gsimalloc(len);
                        if (value == 0)
                            return 6;
                        if (!gsXmlReadChildAsBase64Binary(request->stream, g_021E3E5C, value, &len)) {
                            gsifree(value);
                            return 5;
                        }
                    } else {
                        len = 0;
                        value = 0;
                    }
                    outputField->type = 8;
                    outputField->value.binary.len = len;
                    outputField->value.binary.ptr = value;
                } else {
                    return 22;
                }
            }
        }
    }

    return 0;
}




/*
 * sdk:      sakeiFreeOutputRecord (libdwcgssake.TWL.HYB.a(sakerequestread.o))
 */
void func_021DE840(int numFields, SAKEField *record)
{
    int i;

    if (record == 0)
        return;
    for (i = 0; i < numFields; i++) {
        if (record[i].type == 8 && record[i].value.str != 0)
            func_0217EAE0(record[i].value.str);
        if (record[i].type == 5)
            func_0217EAE0(record[i].value.str);
    }
    func_0217EAE0(record);
}




void func_021DE8AC(int a, int b, Ent **arr)
{
    int i, j;

    if (arr == 0)
        return;
    for (i = 0; i < b; i++) {
        if (arr[i] == 0)
            continue;
        for (j = 0; j < a; j++) {
            if (arr[i][j].type == 8 && arr[i][j].p8 != 0)
                func_0217EAE0(arr[i][j].p8);
            if (arr[i][j].type == 5)
                func_0217EAE0(arr[i][j].p8);
        }
        func_0217EAE0(arr[i]);
        arr[i] = 0;
    }
    func_0217EAE0(arr);
}








/*
 * SDK provenance: sakeiSearchForRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 */
int func_021DE95C(u32_021DE95C ctx)
{
    u32_021DE95C *p = *(u32_021DE95C **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 6;
    if (p[1] == 0)
        return 5;
    if ((int)p[5] < 0)
        return 0xa;
    if ((int)p[6] <= 0)
        return 0xb;
    return func_021DE14C((char **)p[1], p[2]);
}








/*
 * Resolved: the ov175 region hint on d_021E3F04 was contested (another
 * overlapping overlay starts a data object there); un-hinted, sole-ref/data
 * picks the unique overlay start, so all 19 sites resolve and the 280 bytes
 * are exact.
 */
int func_021DE9BC(O *o)
{
    S *s = o->f8;

    func_02182AC0(o->f18, d_021E3DF8, d_021E3EFC, (char *)s->f0);
    if (s->fc) {
        func_02182AC0(o->f18, d_021E3DF8, d_021E3F04, (char *)s->fc);
    }
    if (s->f10) {
        func_02182AC0(o->f18, d_021E3DF8, d_021E3F0C, (char *)s->f10);
    }
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F14, s->f14);
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F1C, s->f18);
    if (s->f1c) {
        func_02182AC0(o->f18, d_021E3DF8, d_021E3F20, (char *)s->f1c);
    }
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F30, s->f20);
    func_021DE26C((u32_021DE95C)o, (u32_021DE95C *)s->f24, s->f28);
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F3C, s->f2c);
    func_021DE184((u32_021DE95C)o, (u32_021DE95C *)s->f4, s->f8);
    return 0;
}








/*
 * Five-argument forward to func_021DE2E0 (ov175): the object itself
 *  *  is the first argument, its +0x0c cursor is passed bare and +4, and the
 *  *  +0x08 block contributes its second and third words.
 */
void func_021DEAD4(char *obj)
{
    u32_021DEAD4 *ip = *(u32_021DEAD4 **)(obj + 8);
    u32_021DEAD4 v = *(u32_021DEAD4 *)(obj + 0xc);
    func_021DE2E0((u32_021DEAD4)obj, v + 4, v, ip[2], ip[1]);
}








/*
 * If the +0x0c cursor is live, forwards its first two words as the
 *  *  second and third arguments and the +0x08 block's +0x08 word as the
 *  *  first to func_021DE8AC (ov175).
 */
void func_021DEAF8(char *obj)
{
    u32_021DEAD4 *cur = *(u32_021DEAD4 **)(obj + 0xc);
    char *blk = *(char **)(obj + 8);
    if (cur == 0)
        return;
    func_021DE8AC(*(u32_021DEAD4 *)(blk + 8), cur[0], (Ent * *)cur[1]);
}








int func_021DEB1C(char *p)
{
    int *q = *(int **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[2] <= 0)
        return 6;
    if (q[1] == 0)
        return 5;
    return func_021DE14C((char **)q[1], q[2]);
}







u32_021DEB5C func_021DEB5C(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    func_02182AC0((void *)(*(u32_021DEB5C *)(obj + 0x18)), (char *)((u32_021DEB5C)g_021E3DF8), (char *)((u32_021DEB5C)g_021E3EFC), (char *)b->f0);
    func_021DE184((u32_021DEB5C)obj, (u32_021DE95C *)((u32_021DEB5C *)b->f4), b->f8);
    return 0;
}







void func_021DEB98(char *obj)
{
    u32_021DEB98 *ip = *(u32_021DEB98 **)(obj + 8);
    u32_021DEB98 v = *(u32_021DEB98 *)(obj + 0xc);
    func_021DE2E0((u32_021DEB98)obj, v + 4, v, ip[2], ip[1]);
}







/*
 * Forward the +0x08 block's third word and the +0x0c cursor's two head words
 * to func_021DE8AC; a null cursor is a no-op.
 */
void func_021DEBBC(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE8AC(r[2], q[0], (Ent * *)q[1]);
}







int func_021DEBE0(void *p)
{
    return func_021DDB10(p, (int)d_021E3CA0);
}







/*
 * SDK provenance: sakeiGetSpecificRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 */
int func_021DEBF4(u32_021DEBF4 ctx)
{
    u32_021DEBF4 *p = *(u32_021DEBF4 **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 0xd;
    if (p[1] == 0)
        return 0xc;
    if ((int)p[4] <= 0)
        return 6;
    if (p[3] == 0)
        return 5;
    return func_021DE14C((char **)p[3], p[4]);
}







/*
 * SDK provenance: sakeiGetSpecificRecordsFillSoapRequest
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Emit the SOAP
 * envelope, the name list and the specific-record table.
 */
int func_021DEC54(u32_021DEC54 ctx)
{
    u32_021DEC54 *p = *(u32_021DEC54 **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3EFC, (void *)p[0]);
    func_021DE1F8(ctx, (u32_021DEC54 *)p[1], p[2]);
    func_021DE184(ctx, (u32_021DE95C *)((u32_021DEC54 *)p[3]), p[4]);
    return 0;
}






void func_021DECA0(char *obj)
{
    u32_021DE95C *ip = *(u32_021DE95C **)(obj + 8);
    u32_021DE95C v = *(u32_021DE95C *)(obj + 0xc);
    func_021DE2E0((u32_021DE95C)obj, v + 4, v, ip[4], ip[3]);
}






/*
 * Forward the +0x08 block's fifth word and the +0x0c cursor's two head words
 * to func_021DE8AC; a null cursor is a no-op.
 */
void func_021DECC4(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE8AC(r[4], q[0], (Ent * *)q[1]);
}






/*
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder to func_021DDB10 with a fixed second argument.
 */
int func_021DECE8(void *p)
{
    return func_021DDB10(p, (int)d_021E3C78);
}





/*
 * SDK provenance: sakeiGetMyRecordsValidateInput
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.
 */
int func_021DECFC(u32_021DECFC ctx)
{
    u32_021DECFC *p = *(u32_021DECFC **)((char *)ctx + 8);

    if (p[0] == 0)
        return 4;
    if ((int)p[2] <= 0)
        return 6;
    if (p[1] == 0)
        return 5;
    return func_021DE14C((char **)p[1], p[2]);
}





int func_021DED3C(u32_021DECFC ctx)
{
    u32_021DECFC *p = *(u32_021DECFC **)((char *)ctx + 8);

    func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3EFC, (void *)p[0]);
    if (p[3] != 0)
        func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3F04, (void *)p[3]);
    func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3F1C, 1);
    func_021DE184(ctx, (u32_021DE95C *)((u32_021DECFC *)p[1]), p[2]);
    return 0;
}





int func_021DEDB4(int **p)
{
    int *t = (int *)p[2];
    int *out = (int *)p[3];
    int *pa;
    int nb;
    int h = func_021DE2E0((u32_021DEAD4)p, (u32_021DEAD4)&pa, (u32_021DEAD4)&nb, t[2], t[1]);

    if (h == 0) {
        if (pa != 0 && nb > 0)
            *out = *pa;
        else
            *out = 0;
    }
    func_0217EAE0(pa);
    return h;
}





/*
 * Voice state tail: the +0x0c cursor is the gate -- a null one returns
 * immediately; otherwise the +0x08 block's third word and the cursor's head
 * word are handed to func_021DE840.
 */
void func_021DEE18(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE840(r[2], (SAKEField *)q[0]);
}
