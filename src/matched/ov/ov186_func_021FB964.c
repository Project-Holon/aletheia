/*
 * function: func_021FB964
 * address: 0x021FB964
 * packet: pkt_ov186_021FB964
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 490F4 receives full heap without truncation; resource helpers use their own u16 heap.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021FB964(void *ctx,unsigned kind,unsigned short heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    switch(kind) {
    case 0:
        func_02049658(h,0x26,3,0,0,0,heap);
        func_020498F4(h,0x28,3,0,0,0,heap);
        break;
    case 1:
        func_02049658(h,0x26,6,0,0,0,heap);
        func_020498F4(h,0x28,6,0,0,0,heap);
        break;
    case 2:
        func_02049658(h,0x6b,0,0,0,0,heap);
        func_020498F4(h,0x2,0,0,0,0,heap);
        break;
    case 3:
        func_02049658(h,0x26,2,0,0,0,heap);
        func_020498F4(h,0x27,2,0,0,0,heap);
        break;
    case 4:
        func_02049658(h,0x26,2,0,0,0,heap);
        func_020498F4(h,0x1a,2,0,0,0,heap);
        break;
    case 5:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x5,5,0,0,0,heap);
        break;
    case 6:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2d,2,0,0,0,heap);
        break;
    case 7:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2c,2,0,0,0,heap);
        break;
    case 8:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2b,2,0,0,0,heap);
        break;
    case 9:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x61,5,0,0,0,heap);
        break;
    case 10:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x63,2,0,0,0,heap);
        break;
    case 11:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x64,2,0,0,0,heap);
        break;
    case 12:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x65,2,0,0,0,heap);
        break;
    case 13:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x66,2,0,0,0,heap);
        break;
    case 19:
        func_02049658(h,0x6b,2,0,0,0,heap);
        func_020498F4(h,0x2,2,0,0,0,heap);
        break;
    case 14:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x62,2,0,0,0,heap);
        break;
    case 15:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x67,5,0,0,0,heap);
        break;
    case 18:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x68,2,0,0,0,heap);
        break;
    case 17:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x69,2,0,0,0,heap);
        break;
    case 16:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x6a,2,0,0,0,heap);
        break;
    case 20:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1f,5,0,0,0,heap);
        break;
    case 21:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1d,5,0,0,0,heap);
        break;
    case 22:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0xd,5,0,0,0,heap);
        break;
    case 23:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0xe,5,0,0,0,heap);
        break;
    case 24:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x3,2,0,0,0,heap);
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,6,5,0,0,0,heap);
        break;
    case 25:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x1b,2,0,0,0,heap);
        break;
    case 26:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1e,5,0,0,0,heap);
        break;
    case 28:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1c,5,0,0,0,heap);
        break;
    case 27:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x20,5,0,0,0,heap);
        break;
    case 29:
        func_02049658(h,0x26,5,0,0,0,heap);
        func_020498F4(h,0x12,5,0,0,0,heap);
        break;
    case 30:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x2f,5,0,0,0,heap);
        break;
    }
    ARC_TOOL_DeleteHandle(h);
}
