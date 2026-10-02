/*
 * function: func_021D75A4
 * address: 0x021D75A4
 * packet: pkt_ov131_021D75A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * output: primary caller7460 guards C38==1; C38->C20->357A0 is
 *   the same flag used by35CB8/35C70. Intervening BA4/hit-test and
 *   singleton/accessor bodies are readonly, so this observed call path
 *   assigns both full u32 coordinate words. Original35760/80 LDRH
 *   zero-extends into r0;35C70 stores each with STR, not STRH.
 * arithmetic: coordinate-minus-byte narrowed to signed byte; unsigned
 *   word subtraction preserves low bits for every input. Previous
 *   direction remains full u32; +/-1 wraps, with no assumed1..4 domain.
 *   Byte history increments have intermediate1..256 then u8 conversion.
 * interface:77E8/77F8 coordinate inputs widened to u32: original call
 *   setup retains full words, while copied u8 externs insert eight-byte
 *   argument masks at each call (r01). Own bodies store only low bytes.
 * residual:7 concrete bytes differ at rotation entry;578 compiled bytes
 *   plus original two-byte zero alignment.12/12 relocations resolved.
 * budgets:5 iteration compiles;3 consecutive nonshrinks starting r03,
 *   3 runs since first nonshrink;2 manual scheduling variants used.
 *   Check3 used2/2;types permuter once300 includes baseline.
 * checks:1 own bodies prove all arities;77E8/F8 widened after r01's masks;
 *   2 no caller twin beyond own77E8/F8/7810 and primary7460;
 *   3 mutable/const p and s8/int deltas tested in iteration;enum flag and
 *   distinct rotation deltas in2 check compiles unchanged at18;
 *   4 masked-width/enum-zero/second-local/const-load idioms read;
 *   5 fresh idiom listing and neighbours read;no stack-aggregate residue.
 * note 2026-10-02 (lane B2-09): 3 concrete bytes differ (+0x124/+0x126/+0x12A).
 *   Original rx: ldrb r1,[r0]; ldr r0,[sp,#4]; subs r0,r0,r1 (x in r0, byte in
 *   r1); compiled puts the byte in r0 and x in r1. Everything else matches:
 *   the r3/r4 zero registers are fixed by writing direction=0 BEFORE
 *   ++p[0x81] and flag=0 AFTER ry (gives movs r3 then movs r4 in the ldrb
 *   slot and the adds r2,r3 zero reuse for -16). Inert for the remaining 3
 *   bytes: operand casts, byte/x locals, inline delta helper, s8/u32 rx,
 *   compound t-=b, struct view of p, declaration order of direction/flag.
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_021D77E8 0x021D77E8 thumb ov131
 *   func_021D77F8 0x021D77F8 thumb ov131
 *   func_021D7810 0x021D7810 thumb ov131
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef enum { D0,D1,D2,D3,D4 } Direction;
typedef enum { F0,F1 } Flag;
struct hdr { u8 f0,f1,f2,f3; int f4; };
typedef struct { u8 pad[0x94]; u8 ring[5]; u8 f99,f9a; } Ring;
extern u32 func_02035CB8(u32 *,u32 *);
extern void func_021D77E8(u8 *,u32,u32);
extern void func_021D77F8(struct hdr *,u32,u32,int);
extern void func_021D7810(int,Ring *,int);
void func_021D75A4(int a,u8 *p)
{
    u32 x,y;
    int dx,dy,rx,ry;
    Direction direction;
    Flag flag;
    u32 tmp;
    u32 *tmp1;
    func_02035CB8(&x,&y);
    dx=(s8)(x-p[0x7a]);
    dy=(s8)(y-p[0x7b]);
    if ((*(u32 *)(p+0x7c)==0 || *(u32 *)(p+0x7c)==3) && dx>16)
        func_021D77F8((struct hdr *)(p+0x78),x,y,1);
    if (*(u32 *)(p+0x7c)<=1 && dx < -16)
        func_021D77F8((struct hdr *)(p+0x78),x,y,3);
    if (dy>16 || dy < -16 || p[0x79]>20)
        func_021D77E8((u8 *)p+0x78,x,y);
    ++((u8 *)p)[0x79];
    dx=(s8)(x-p[0x82]);
    dy=(s8)(y-p[0x83]);
    if ((*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==4) && dy>16)
        func_021D77F8((struct hdr *)(p+0x80),x,y,2);
    if ((*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==2) && dy < -16)
        func_021D77F8((struct hdr *)(p+0x80),x,y,4);
    if (dx>16 || dx < -16 || p[0x81]>20)
        func_021D77E8((u8 *)p+0x80,x,y);
    direction=0;
    ++((u8 *)p)[0x81];
    rx=(s8)(x-p[0x8a]);
    ry=(s8)(y-p[0x8b]);
    flag=0;
    if (rx>16) direction=1;
    else if (rx < -16) direction=3;
    else if (ry>16) direction=2;
    else if (ry < -16) direction=4;
    if (direction!=0 && (u32)direction!=*(u32 *)(p+0x8c)) {
        if (*(u32 *)(p+0x8c)+1==(u32)direction ||
            (*(u32 *)(p+0x8c)==4 && direction==1)) {
            tmp=*(u32 *)(p+0x90);
            if (tmp<=1) {
                *(u32 *)(p+0x90)=1;
                func_021D77F8((struct hdr *)(p+0x88),x,y,direction);
                if (*(u32 *)(p+0x8c)==4) flag=1;
            } else {
                *(u32 *)(p+0x90)=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (*(u32 *)(p+0x8c)-1==(u32)direction ||
            (*(u32 *)(p+0x8c)==1 && direction==4)) {
            tmp1=(u32 *)(p+0x90);
            if (*tmp1==2 || *(u32 *)(p+0x90)==0) {
                *(u32 *)(p+0x90)=2;
                func_021D77F8((struct hdr *)(p+0x88),x,y,direction);
                if (*(u32 *)(p+0x8c)==4) flag=1;
            } else {
                *(u32 *)(p+0x90)=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (*(u32 *)(p+0x8c)==0) {
            *(u32 *)(p+0x8c)=direction;
        }
    }
    if (p[0x89]>20) {
        *(u32 *)(p+0x90)=0;
        func_021D77E8((u8 *)p+0x88,x,y);
    }
    func_021D7810(a,(Ring *)p,flag);
    ++((u8 *)p)[0x89];
}
