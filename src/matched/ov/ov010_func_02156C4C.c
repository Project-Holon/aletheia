/*
 * function: MUSICAL_DRESSUP_SYS_Main
 * address:  0x02156C4C
 * packet:   pkt_ov010_02156C4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recovered existing source/shard: setup MUSICAL_DRESSUP_SYS_Init loads ov133 (0x85).
 * Its constructor returns the allocation; ov070's same address is a setter.
 * The ov132 getter reads its session argument at +0x48, passed live in r0.
 * The 94-byte body is followed by two bytes of alignment padding.
 *
 * symbols:
 *   DUP_FITTING_Create  0x021B6100  thumb ov133
 *   DUP_FITTING_Main  0x021B63BC  thumb  ov133
 *   DUP_FITTING_Delete  0x021B6294  thumb ov133
 *   STA_NET_GetRole  0x021FD904  thumb ov132
 *   STA_NET_BeginTransfer  0x021FD52C  thumb ov132
 */

typedef unsigned char  u8;
extern u8 *DUP_FITTING_Create(u8 *parent, int heap);
extern int DUP_FITTING_Main(int);
extern void DUP_FITTING_Delete(char *p);
extern int STA_NET_GetRole(int *);
typedef struct S S;
extern void STA_NET_BeginTransfer(struct S *s);

int MUSICAL_DRESSUP_SYS_Main(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)DUP_FITTING_Create((u8 *)d[0], 0x2d);
        *state = 1;
        if (*(int *)d[3] != 0) {
            if (STA_NET_GetRole((int *)*(int *)d[3]) == 1)
                STA_NET_BeginTransfer((S *)*(int *)d[3]);
        }
        break;
    case 1: {
        int r = DUP_FITTING_Main(d[1]);
        if (r != 0) {
            d[2] = r;
            *state = 2;
        }
        break;
    }
    case 2:
        DUP_FITTING_Delete((char *)d[1]);
        return 1;
    }
    return 0;
}
