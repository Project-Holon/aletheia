/*
 * function: GDS_SOCKET_WaitToken
 * address: 0x021D8444
 * packet: pkt_ov125_021D8444
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * note: pass 5 2026-10-06 P5L06: EXACT (also with --lang c). Written in the style of the matched sibling
 *   021D7A10: gGdsSocket as a char array read through a D() offset macro (no named base pointer), the
 *   token copy through a named Sav pointer and the 0x138-byte record copy as an int-array struct, under
 *   opt_propagation off. The earlier 14-byte form differed only by a named `char *g` base pointer; with it
 *   the Sav destination took ip and the record copy counter (mov r5,#0x13) was scheduled above the trailing
 *   strb. Without the pragma this form gives the old 18 bytes (source and destination colours swapped).
 * symbols:
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   DWC_GetLastErrorEx 0x02059E38 arm
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   GDS_SOCKET_Sleep 0x021D8438 arm ov125
 *   gGdsSocket 0x021D9E40 data a4
 *   sGdsSvlService 0x021D8D30 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[301]; } Sav;
typedef struct { int w[0x138 / 4]; } Blob;
extern int func_02167FA8(char *svl, void *result);
extern int func_02168040(void);
extern int DWC_GetLastErrorEx(int *, int *);
extern void GDS_SOCKET_Lock(void);
extern void GDS_SOCKET_Unlock(void);
extern void GDS_SOCKET_Sleep(int);
extern char gGdsSocket[];
extern const char sGdsSvlService[];
#define D(o) (*(int *)(gGdsSocket + (o)))

#pragma opt_propagation off
int GDS_SOCKET_WaitToken(void)
{
    u8 buf[0x174];
    int b, a;
    int r;

    if (D(0x138) == 1)
        return 1;
    if (func_02167FA8((char *)sGdsSvlService, buf) == 0) {
        D(0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            Sav *t = (Sav *)(gGdsSocket + 6);
            *t = *(Sav *)(buf + 0x45);
            *(Blob *)(*(char **)&D(0x258) + 8) = *(Blob *)gGdsSocket;
            D(0x138) = 1;
            return 1;
        }
        if (r == 4) {
            DWC_GetLastErrorEx(&a, &b);
            D(0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            D(0x250) = 0xE;
            return 0;
        }
        GDS_SOCKET_Lock();
        if (D(0x268) == 1) {
            D(0x250) = 0xD;
            GDS_SOCKET_Unlock();
            return 0;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
}
#pragma opt_propagation reset
