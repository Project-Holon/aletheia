/*
 * function: func_0215BF88
 * address:  0x0215BF88
 * packet:   (none, pending)
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (65 bytes; size now exact at 880)
 * notes:    the 0x35 arm is a switch on s[1] with case 2 / case 5, not
 *           if/else-if: the if/else-if spelling (which it had) makes the
 *           compiler predicate the ==2 arm inline and branch over it, costing
 *           the image's out-of-line arm and one instruction -- 240 bytes and
 *           -4 on the extent.  With the switch the extent is 880 and the
 *           residue is 65 bytes, all of it the tie between the option pointer
 *           (s += 0xf0) and the `dhcp_mode & 2` mask: image keeps the pointer
 *           in r3 and the mask in ip, this compile swaps them, and the swap
 *           drags the scheduling with it -- image `addeq r3, r5, #0xf0` (the
 *           address add predicated into the && chain, before the last
 *           `cmpeq r0, #0x63`) where this compile emits an unconditional
 *           `add ip, r5, #0xf0` after the `bne`.  `mode` must stay a named
 *           local (writing `g_021A826C.dhcp_mode & 2` inline in case 6 drops
 *           the whole allocation: 868 bytes, 678 out).  Tried and inert:
 *           mode at function scope, mode as a declaration initialiser, mode
 *           before vs after `s += 0xf0`, `s = s + 0xf0`, a named `opt`
 *           pointer local (888 bytes), swapping the case order, else-if
 *           nesting, store-before-result, `int` for `u32` mode.
 *
 * sdk:      dhcp_analyze_response (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   func_0215B504                    0x0215b504 arm ov009
 *   func_02157390                    0x02157390 arm ov009
 *   func_0215AEB0                    0x0215aeb0 arm ov009
 *   func_021579BC                    0x021579bc arm ov009
 *   func_0215B064                    0x0215b064 arm ov009
 *   g_021A1C9C                       0x021a1c9c data
 *   g_021A82D4                       0x021a82d4 data
 *   g_021A826C                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct CPSVars {
    u8 pad0[0xc];
    u32 dhcp_mode;
    u32 netmask;
    u8 pad14[4];
    int (*link_is_on)(void);
    u32 dhcp_server;
    u8 pad20[0x2c - 0x20];
    u32 gateway;
    u8 pad30[0x38 - 0x30];
    u32 offered_myip;
    u32 lease_time;
    u8 pad40[0x50 - 0x40];
    u32 myip;
    u8 pad54[0x70 - 0x54];
    u32 dns[2];
};

extern u8 g_021A1C9C[];
extern u8 g_021A82D4[];
extern struct CPSVars g_021A826C;
extern unsigned long long OS_GetTick(void);
extern u32 func_0215B504(void);
extern void func_02157390(void);
extern u8 *func_0215AEB0(u32 *len);
extern int func_021579BC(u8 *a, u8 *b);
extern void func_0215B064(u32 len);

#define TICK() ((u32)(OS_GetTick() >> 16))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))
#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))

int func_0215BF88(u32 id, int retry)
{
    u8 *s;
    u8 *end;
    u32 len;
    u32 start;
    int result;
    u32 myip_tmp;
    u8 c;
    long timeout;

    timeout = g_021A1C9C[retry] * 7;
    start = TICK();
    result = 0;
    while (g_021A826C.link_is_on() && result == 0 && (long)(TICK() - start) < timeout) {
        if (func_0215B504() == 0) {
            func_02157390();
            continue;
        }
        s = func_0215AEB0(&len);
        if (len > 0xf0 && s[0] == 2 && NTOHL(s + 4) == id && func_021579BC(s + 0x1c, g_021A82D4) == 0) {
            myip_tmp = G32(s + 0x10);
            end = s + len;
            result = 3;
            if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 && s[0xef] == 0x63) {
                u32 mode;
                s += 0xf0;
                mode = g_021A826C.dhcp_mode & 2;
                while (s < end && (c = *s++) != 0xff) {
                    if (c == 0)
                        continue;
                    switch (c) {
                    case 1:
                        g_021A826C.netmask = G32(s + 1);
                        break;
                    case 3:
                        g_021A826C.gateway = G32(s + 1);
                        break;
                    case 6:
                        if (mode == 0) {
                            if (s[0] < 8)
                                g_021A826C.dns[1] = 0;
                            else
                                g_021A826C.dns[1] = G32(s + 5);
                            g_021A826C.dns[0] = G32(s + 1);
                        }
                        break;
                    case 0x33:
                        g_021A826C.lease_time = G32(s + 1);
                        break;
                    case 0x35:
                        switch (s[1]) {
                        case 2:
                            result = 1;
                            g_021A826C.offered_myip = myip_tmp;
                            break;
                        case 5:
                            result = 2;
                            g_021A826C.myip = myip_tmp;
                            break;
                        }
                        break;
                    case 0x36:
                        g_021A826C.dhcp_server = G32(s + 1);
                        break;
                    }
                    s += *s + 1;
                }
            }
        }
        func_0215B064(len);
    }
    return result;
}
