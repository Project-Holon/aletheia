/*
 * function: FIELD_SUBPROC_MGR_Delete
 * address:  0x021BB90C
 * packet:   pkt_ov021_021BB90C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_SUBPROC_End  0x021BBA1C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    char b[0x18];
} E18;

typedef struct {
    int f0;
    int f4;
    int n;
    E18 *arr;
    void *f10;
    void *f14;
} Obj;

extern void FIELD_SUBPROC_End(int *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void FIELD_SUBPROC_MGR_Delete(Obj *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        FIELD_SUBPROC_End((int *)(&p->arr[i]));
    }
    func_020307B0(p->arr);
    func_020307B0(p->f10);
    func_020307B0(p->f14);
    func_020307B0(p);
}
