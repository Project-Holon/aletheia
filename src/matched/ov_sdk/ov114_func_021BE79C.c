/*
 * function: func_021BE79C
 * address:  0x021BE79C
 * packet:   pkt_ov114_021BE79C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_AddPostDataRaw (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEC10 0x021BEC10 arm ov114
 */

typedef struct {
    int f0;
    int f4;
    char pad[8];
    int f10;
    char pad2[0x20];
    void *f34;
    char pad3[0x214];
    void *f24c;
    unsigned long f250;
} Req;

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern void *func_021BEF58(void);
extern Req *func_021BEC10(void *mutexInfo_p, void *handle_p);

int func_021BE79C(void *handle, void *value_p, unsigned long length)
{
    Req *req_p;
    void *mutexInfo_p;

    func_021BEF08();
    mutexInfo_p = func_021BEF58();
    req_p = func_021BEC10(mutexInfo_p, handle);
    if (req_p == 0) {
        return -1;
    }
    if (req_p->f4 != 0) {
        return -1;
    }
    if (req_p->f34 != 0) {
        return -1;
    }
    req_p->f10 = 1;
    req_p->f24c = value_p;
    req_p->f250 = length;
    return 0;
}
