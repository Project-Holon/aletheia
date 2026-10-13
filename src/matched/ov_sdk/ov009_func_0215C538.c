/*
 * function: resolve_common
 * address:  0x0215C538
 * packet:   pkt_ov009_0215C538
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      resolve_common (libcps.TWL.HYB.a network.o)
 * symbols:
 *   CPS_SocWrite                    0x0215b470 arm ov009
 *   OS_GetTick                       0x020870d0 arm
 *   CPS_SocGetLength                    0x0215b504 arm ov009
 *   OS_Sleep                         0x02085a38 arm
 *   CPS_SocRead                    0x0215aeb0 arm ov009
 *   dns_skipname                    0x0215c508 arm ov009
 *   MI_CpuCopy                       0x02082ea4 arm
 *   CPS_SocConsume                    0x0215b064 arm ov009
 *   g_021A826C                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct CPSVars {
    u8 pad0[0x18];
    int (*link_is_on)(void);
};

extern struct CPSVars g_021A826C;
extern u32 CPS_SocWrite(u8 *buf, u32 len);
extern unsigned long long OS_GetTick(void);
extern long CPS_SocGetLength(void);
extern void OS_Sleep(u32 msec);
extern u8 *CPS_SocRead(u32 *len);
extern u8 *dns_skipname(u8 *p);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern void CPS_SocConsume(u32 len);

#define TICK() ((u32)(OS_GetTick() >> 16))
#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define GET16(p) ((u16)((p)[1] | ((p)[0] << 8)))
static inline u16 get16(u8 *p)
{
    return (u16)((p[0] << 8) | p[1]);
}

u32 resolve_common(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max)
{
    u8 outbuf[68];
    u8 *buf;
    u8 *d;
    u8 *d0;
    u32 len;
    u32 cnt;
    u8 c;
    u32 ip;
    u32 start;
    u8 *end;

    *(u16 *)(outbuf + 0) = HTONS(id);
    if (type != 0x20)
        *(u16 *)(outbuf + 2) = 0x0001;
    else
        *(u16 *)(outbuf + 2) = 0x1001;
    *(u16 *)(outbuf + 4) = 0x100;
    *(u16 *)(outbuf + 6) = 0;
    *(u16 *)(outbuf + 8) = 0;
    *(u16 *)(outbuf + 10) = 0;
    d0 = outbuf + 12;
    d = d0 + 1;
    len = 0;
    while ((c = *name++) != 0) {
        if (d - outbuf > 0x3c)
            return 0xffffffff;
        if (c != '.') {
            len++;
            *d++ = c;
        } else if (len != 0) {
            *d0 = len;
            d0 = d;
            len = 0;
            d++;
        }
    }
    *d0 = len;
    ip = 0;
    d[0] = 0;
    d[1] = type >> 8;
    d[2] = type;
    d[3] = 0;
    d[4] = 1;
    CPS_SocWrite(outbuf, d + 5 - outbuf);
    start = TICK();
    while (g_021A826C.link_is_on() && ip == 0 && (int)(TICK() - start) < 0xf) {
        if (CPS_SocGetLength() == 0) {
            OS_Sleep(10);
            continue;
        }
        buf = CPS_SocRead(&len);
        if (len > 12 && HTONS(*(u16 *)buf) == id) {
            if ((buf[3] & 0xf) == 3) {
                ip = 0xffffffff;
            } else if ((buf[3] & 0xf) == 0) {
                end = buf + len;
                d = buf + 12;
                cnt = GET16(buf + 4);
                while (cnt-- != 0)
                    d = dns_skipname(d) + 4;
                while (d < end) {
                    d = dns_skipname(d);
                    cnt = get16(d + 8);
                    if (get16(d) == type) {
                        if (type != 0xc) {
                            ip = ((u32)get16((u8 *)((u32)d + 6 + cnt)) << 16) | get16((u8 *)((u32)d + 8 + cnt));
                        } else if (cnt > rname_max) {
                            ip = 2;
                        } else {
                            MI_CpuCopy(d + 10, rname, cnt);
                            ip = 1;
                        }
                        break;
                    }
                    d += cnt + 10;
                }
            }
        }
        CPS_SocConsume(len);
    }
    return ip;
}
