/*
 * function: GFL_NET_SYSTEM_ProcessRecvRing
 * address:  0x02038DF0
 * packet:   pkt_02038DF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A50   0x020A7A50  data
 *   func_0203D798  0x0203D798  arm
 *   GFL_NET_RING_BUFF_GetDataSize  0x020365E8  arm
 *   GFL_NET_RING_BUFF_ReadU16  0x02036540  arm
 *   GFL_NET_RING_BUFF_ReadByte  0x02036500  arm
 *   GFL_NET_RING_BUFF_Read  0x020364D4  arm
 *   GFL_NET_COMMAND_IsHugeCommand  0x0203A804  arm
 *   GFL_NET_COMMAND_IsCommandValid  0x0203A7EC  arm
 *   GFL_NET_COMMAND_GetHeaderSize  0x0203A634  arm
 *   GFL_NET_COMMAND_GetHugeBuffer  0x0203A81C  arm
 *   func_02082D44  0x02082D44  arm
 *   GFL_NET_SYSTEM_DispatchRecv  0x02038D68  arm
 *   func_02034714  0x02034714  arm
 *
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header GFL_NET_RING_BUFF_Init builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - GFL_NET_RING_BUFF_Read is written in BOTH arms of the GFL_NET_COMMAND_IsHugeCommand test,
 *       if (!GFL_NET_COMMAND_IsHugeCommand(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     GFL_NET_RING_BUFF_ReadU16's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Src {
    u8  pad00[0x0c];
    s16 pos;
};

struct St {
    s32 done;
    u8 *dst;
    u16 left;
    u16 total;
    u16 h;
    u8  f0E;
    u8  f0F;
};

extern const u8 str_020A7A24[];
extern const u8 str_020A7A50[];
extern void *func_0203D798(void);
extern int GFL_NET_RING_BUFF_GetDataSize(char *p);
extern u32 GFL_NET_RING_BUFF_ReadU16(u32 a);
extern u32 GFL_NET_RING_BUFF_ReadByte(u32 a);
extern int  GFL_NET_RING_BUFF_Read(struct Src *s, u8 *buf, u32 n, u32 max);
extern int  GFL_NET_COMMAND_IsHugeCommand(u32 h);
extern int  GFL_NET_COMMAND_IsCommandValid(u32 h);
extern u32 GFL_NET_COMMAND_GetHeaderSize(u32 a0);
extern u32 GFL_NET_COMMAND_GetHugeBuffer(u32 a0, u32 a1, u32 a2);
extern void func_02082D44(void *dst, const void *src, int n);
extern void GFL_NET_SYSTEM_DispatchRecv(int a0, u32 a1, u32 a2, u8 *a3);
extern void func_02034714(const char *expr, u32 line, const char *file);

void GFL_NET_SYSTEM_ProcessRecvRing(struct Src *src, u32 a1, u8 *buf, struct St *st, u32 n)
{
    int len;
    s16 sv;
    u8 *p;
    u32 h;
    int cnt;

    func_0203D798();
    while (GFL_NET_RING_BUFF_GetDataSize((char *)src) != 0) {
        h = st->h;
        if (h == 0) {
            h = GFL_NET_RING_BUFF_ReadU16((u32)src);
            if (h == 0) {
                func_02034714((const char *)str_020A7A24, 0x6E3, (const char *)str_020A7A50);
                continue;
            }
        }
        sv = src->pos;
        st->h = h;
        if (st->total == 0xFFFF) {
            if (GFL_NET_RING_BUFF_GetDataSize((char *)src) < 3) {
                src->pos = sv;
                return;
            }
            {
                u16 v = GFL_NET_RING_BUFF_ReadU16((u32)src);
                st->left = v;
                st->total = v;
            }
            st->f0E = a1;
            st->f0F = GFL_NET_RING_BUFF_ReadByte((u32)src);
        }
        sv = src->pos;
        if (GFL_NET_COMMAND_IsHugeCommand(h) && GFL_NET_COMMAND_GetHeaderSize(st->f0F)) {
            if (st->dst == 0)
                st->dst = (u8 *)GFL_NET_COMMAND_GetHugeBuffer(h, st->f0E, st->total);
            p = st->dst + st->done;
        } else {
            p = buf;
            st->dst = buf;
        }
        if (!GFL_NET_COMMAND_GetHeaderSize(st->f0F))
            p = 0;
        if (!GFL_NET_COMMAND_IsHugeCommand(h))
            len = GFL_NET_RING_BUFF_Read(src, buf, st->left, st->left);
        else
            len = GFL_NET_RING_BUFF_Read(src, buf, st->left, n - 7);
        st->left = st->left - (u16)len;
        cnt = len;
        if (st->total > st->done) {
            cnt = st->total - st->done;
            if (cnt > len)
                cnt = len;
            if (p != 0)
                func_02082D44(buf, p, cnt);
        }
        st->done += cnt;
        if (st->left == 0) {
            GFL_NET_SYSTEM_DispatchRecv(h, st->total, (u32)st->dst, (u8 *)st);
            continue;
        }
        if (!GFL_NET_COMMAND_IsCommandValid(h))
            return;
        if (GFL_NET_COMMAND_IsHugeCommand(h))
            return;
        if (!GFL_NET_COMMAND_GetHeaderSize(st->f0F))
            return;
        st->left += (u16)len;
        src->pos = sv;
        return;
    }
}
