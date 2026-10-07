/*
 * file:     pms_input_view_p03.c
 * unit:     yes
 * function: func_021B9720, func_021B97AC, func_021B9814, func_021B98A0, func_021B98F8, func_021B999C
 * address:  0x021B9720
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202414C 0x0202414C thumb
 *   func_02024888 0x02024888 thumb
 *   func_02024994 0x02024994 thumb
 *   func_02024160 0x02024160 thumb
 *   d_021C1C88 0x021C1C88 data ov110 a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void *func_0202414C(char *p);
extern u16 func_02024888(u32 idx, u16 add);
extern int func_02024994(const u32 *p, u32 idx);
extern int func_02024160(void *);
u32 func_021B9720(u8 *p, u16 *src, u32 n, u16 *out);
u32 func_021B97AC(u8 *p,const u16 *ids,u32 count,u16 *out);
u32 func_021B9814(u8 *p, u16 *src, u32 n, u16 *out);
void func_021B98A0(u8 *p);
u32 func_021B98F8(u8 *p, u16 *src, u16 *out, u32 n);
u32 func_021B999C(u8 *p, int i);
extern u8 *const d_021C1C88[];

/*
 * note: 2026-10-04 (wD2 lane06): MATCH. Locals declared o, limit, count, base, i; `base = ...; count = 0; limit = ...` in that order fixed the zero register and slots. Only unresolved relocations are arm9 leaves 0x0202414C and 0x02024994, filed as src/matched/arm9 EXACT leaves this wave (need manifest witness).
 */
u32 func_021B9720(u8 *p, u16 *src, u32 n, u16 *out)
{
    void *o;
    u32 limit;
    u32 count;
    u32 base;
    u32 i;
    o = func_0202414C((char *)(*(u32 *)p));
    base = func_02024888(0x97, 0);
    count = 0;
    limit = (u16)(base + 7);
    for (i = 0; i < n; i++) {
        u32 v = src[i];
        if (v >= base && v <= limit) {
            if (func_02024994(o, v - base) == 0)
                continue;
        }
        v = src[i];
        p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
        *out = v;
        out++;
        count++;
    }
    return count;
}

u32 func_021B97AC(u8 *p,const u16 *ids,u32 count,u16 *out)
{
    u32 i;
    u32 n;
    if(!func_02024160(*(void **)p))return 0;
    i=0;
    n=0;
    for(;i<count;i++){
        u32 id=ids[i];
        p[0x1D6E + (id>>3)] |= (u8)(1<<(id&7));
        *out++=i+0x801;
        n++;
    }
    return n;
}

u32 func_021B9814(u8 *p, u16 *src, u32 n, u16 *out)
{
    u32 i;
    for (i = 0; i < n; i++) {
        u32 c = *src;
        if (c == 0xFFFE) {
            u32 len;
            src++;
            len = *src++;
            while (len != 0) {
                u32 v = *src++;
                p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
                len--;
            }
            *out = src[-1];
        } else {
            p[0x1D6E + (c >> 3)] |= (u8)(1 << (c & 7));
            src++;
            *out = c;
        }
        out++;
    }
    return n;
}

void func_021B98A0(u8 *p) {
    u32 a = 0xF58;
    u32 b;
    u32 c;
    u32 i;
    u32 offset = 0;
    a -= 0x6C;
    b = 0xF58;
    b -= 0xD8;
    c = 0xF58;
    c -= 0xD8;
    for (i=0; i<27; ++i) {
        u8 *src = d_021C1C88[i];
        *(u32 *)(p+i*4+a) = offset;
        *(u32 *)(p+i*4+b) = func_021B98F8(p, (u16 *)src, (u16 *)(p+0xF58), offset);
        offset += *(u32 *)(p+i*4+c);
    }
}

u32 func_021B98F8(u8 *p, u16 *src, u16 *out, u32 n)
{
    u32 count = 0;
    u32 c = *src;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            u32 len;
            u32 i;
            src++;
            len = *src++;
            for (i = 0; i < len; i++) {
                u32 v = src[i];
                if (p[0x1D6E + (v >> 3)] & (1 << (v & 7))) {
                    out[n++] = v;
                    count++;
                    break;
                }
            }
            src += len;
        } else {
            if (p[0x1D6E + (c >> 3)] & (1 << (c & 7))) {
                out[n++] = c;
                count++;
            }
            src++;
        }
        c = *src;
    }
    return count;
}


u32 func_021B999C(u8 *p, int i) { return *(u32 *)(p + i * 4 + 8); }
