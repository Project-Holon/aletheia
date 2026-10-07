/*
 * file:     unit_021BBB28_p01.c
 * unit:     yes
 * function: func_021BBB28, func_021BBBC8
 * address:  0x021BBB28
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_free                     0x021ba850 arm
 *   NHTTPi_Response2Connection      0x021bebf0 arm
 *   func_021BAFA0  0x021BAFA0  arm    ov114
 *   func_021BB12C  0x021BB12C  arm    ov114
 *   func_021BB0BC  0x021BB0BC  arm    ov114
 */
struct _NHTTPMutexInfo;
typedef unsigned char u8;

typedef unsigned int u32;

struct _NHTTPConnection {
    char pad_0x00[0x14];
    int field_0x14;
};

struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *field_0x00;
};

struct _NHTTPRes {
    char pad_0x00[0x1c];
    void *field_0x1c;
    void *field_0x20;
    void *field_0x24;
    void *field_0x28;
    char pad_0x2c[0x30 - 0x2c];
    void (*field_0x30)(void *, void *, void *);
    struct _NHTTPi_HDRBUFLIST *field_0x34;
    char pad_0x38[0x438 - 0x38];
    void *field_0x438;
};

typedef struct {
    volatile int len;
} Res;

extern void NHTTPi_free(void *);
extern struct _NHTTPConnection *NHTTPi_Response2Connection(struct _NHTTPMutexInfo *, struct _NHTTPRes *);
extern int func_021BAFA0(const Res *res, int pos, int limit, int *colon, int *rcsize);
extern int func_021BB12C(const Res *res, int pos, int limit, char *str, char extdeli);
extern int func_021BB0BC(const Res *res, int pos, int limit);
void NHTTPi_DestroyResponse(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPRes *res_p);
int func_021BBBC8(const Res *res_p, char *label_p, int *pos_p);


void NHTTPi_DestroyResponse(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPRes *res_p)
{
    struct _NHTTPi_HDRBUFLIST *list_p = res_p->field_0x34;
    struct _NHTTPConnection *connection_p;

    while (list_p != 0) {
        struct _NHTTPi_HDRBUFLIST *next = list_p->field_0x00;
        NHTTPi_free(list_p);
        list_p = next;
        res_p->field_0x34 = list_p;
    }
    if (res_p->field_0x20 != 0)
        NHTTPi_free(res_p->field_0x20);
    if (res_p->field_0x24 != 0)
        NHTTPi_free(res_p->field_0x24);
    if (res_p->field_0x30 != 0) {
        res_p->field_0x30(res_p->field_0x28, (void *)NHTTPi_free, res_p->field_0x438);
        res_p->field_0x28 = 0;
        res_p->field_0x1c = 0;
    }
    connection_p = NHTTPi_Response2Connection(mutexInfo_p, res_p);
    if (connection_p != 0)
        connection_p->field_0x14 = 0;
    NHTTPi_free(res_p);
}


/*
 * notes: EXACT. `volatile int len` forces the per-iteration len reload (image reloads len for the valueend call after the compare); `const Res *res_p` (and on the callee prototypes) schedules the len load before the stack-argument store, matching the image. Levers: a-re-read-loop-bound-is-a-volatile-field and a-const-source-pointer-pulls-field-loads-up-next-to-the-call-result.
 *
 * sdk:      NHTTPi_getHeaderValue (libnhttp.TWL.HYB.a nhttp_response.o)
 */
int func_021BBBC8(const Res *res_p, char *label_p, int *pos_p)
{
    int linetop;
    int nextlinetop;
    int labelend;
    int valuetop;
    int valueend;
    int return_code_size;

    return_code_size = 0;
    linetop = func_021BAFA0(res_p, 12, res_p->len, &labelend, &return_code_size);
    while (linetop > 0) {
        valueend = 0;
        nextlinetop = func_021BAFA0(res_p, linetop, res_p->len, &labelend, &return_code_size);
        if (labelend > 0 && func_021BB12C(res_p, linetop, labelend, label_p, 0) == 0) {
            if (labelend + 1 < res_p->len) {
                valueend = func_021BAFA0(res_p, labelend + 1, res_p->len, 0, &return_code_size);
                if (valueend <= 0) {
                    valueend = res_p->len;
                } else {
                    if (valueend < return_code_size)
                        return -1;
                    valueend = valueend - return_code_size;
                }
                valuetop = func_021BB0BC(res_p, labelend + 1, valueend);
                if (valuetop < 0)
                    valuetop = valueend;
                *pos_p = valuetop;
                return valueend - valuetop;
            }
            return valueend;
        }
        linetop = nextlinetop;
    }
    return -1;
}
