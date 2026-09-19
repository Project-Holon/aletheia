/*
 * function: func_02012CE0
 * address:  0x02012CE0
 * packet:   pkt_02012C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020127A4  0x020127A4  thumb
 *   func_020087E8  0x020087E8  thumb
 *   func_02008860  0x02008860  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0200EE64  0x0200EE64  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200BE54  0x0200BE54  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_0200A864  0x0200A864  thumb
 *   func_0200A870  0x0200A870  thumb
 *   func_0200B3B0  0x0200B3B0  thumb
 *   func_0200892C  0x0200892C  thumb
 *   func_0200894C  0x0200894C  thumb
 *   func_0200895C  0x0200895C  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D08  0x02009D08  thumb
 *   func_020097F0  0x020097F0  thumb
 *   func_0200E884  0x0200E884  thumb
 *   func_02008748  0x02008748  thumb
 *   func_02008658  0x02008658  thumb
 *   func_0200863C  0x0200863C  thumb
 *
 * 204 bytes, 0x02012CE0..0x02012DAC, EXACT on the first run after the one
 * change that mattered: the u32 at p+0x15C is read once into a NAMED local and
 * handed to both 0x0200892C and 0x0200894C.  Spelled inline at each call site
 * the compiler re-materialises the address per site (`adds r1, r6, #0;
 * adds r1, #0x5c; ldr r0, [r5, r6]`) and loses four bytes; with the local it
 * keeps the value live in r7 across the two calls, exactly as the original
 * does.  The third use (0x0200895C, after two more calls) re-reads it, which
 * is also what the original does.
 *
 * p is a byte pointer: the offsets 0x15C / 0x1B8 / 0x1C4 / 0x1C5 / 0x5EC /
 * 0x694 / 0x6AC are plain byte displacements, and mwcc materialises 0x5EC as
 * a pool word (it is not a single-instruction ARM immediate).
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32  func_020127A4(void *p);
extern void func_020087E8(u32 h, u32 v);
extern void func_02008860(u32 h, u32 v);
extern u32  func_02012964(void *p);
extern void func_0200EE64(u32 a, u32 b);
extern u32  func_020071CC(u32 h, u32 id);
extern void func_0200BE54(u32 h, u32 v);
extern u32  func_020127B8(void *p);
extern u32  func_020127C4(void *p);
extern u32  func_0200A864(u32 h);
extern void func_0200A870(u32 a, u32 b);
extern void func_0200B3B0(void *p, u32 h);
extern void func_0200892C(u32 a, u32 b);
extern void func_0200894C(u32 a, u32 b);
extern u32  func_0201283C(void *p);
extern u32  func_02009D08(u32 h);
extern void func_020097F0(u32 a, u32 b);
extern void func_0200895C(u32 a, u32 b);
extern void func_0200E884(void *p, u32 h);
extern u32  func_02008748(u32 h);
extern void func_02008658(u32 a);
extern void func_0200863C(u32 a, u32 b);

void func_02012CE0(u8 *p)
{
    u32 v;
    u32 h;

    v = func_020127A4(p);
    func_020087E8(*(u32 *)p, v);
    func_02008860(*(u32 *)p, v);

    v = func_02012964(p);
    func_0200EE64(v, func_020071CC(*(u32 *)p, 0x29));

    func_0200BE54(*(u32 *)p, func_020127B8(p));

    v = func_020127C4(p);
    func_0200A870(func_0200A864(*(u32 *)p), v);

    func_0200B3B0(p + 0x5EC, *(u32 *)p);

    h = *(u32 *)(p + 0x15C);
    func_0200892C(h, *(u32 *)(p + 0x1B8));
    func_0200894C(h, *(u8 *)(p + 0x1C4));

    v = func_0201283C(p);
    func_020097F0(v, func_02009D08(*(u32 *)p));

    func_0200895C(*(u32 *)(p + 0x15C), *(u8 *)(p + 0x1C5));

    func_0200E884(p + 0x694, *(u32 *)p);

    v = func_02008748(*(u32 *)p);
    func_02008658(*(u32 *)(p + 0x6AC));
    func_0200863C(v, *(u32 *)(p + 0x6AC));
}
