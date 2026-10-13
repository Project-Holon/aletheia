/*
 * function: func_021C0898
 * address: 0x021C0898
 * packet: pkt_ov208_021C0898
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 */
typedef unsigned char u8;
struct Rec;
struct Descriptor;
struct PrintSys;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
void func_021C0898(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 2; i++) MSGDATA_Delete(*(struct Rec **)(p + i * 4 + 0xc));
    for (i = 0; i < 4; i++) {
        *(unsigned *)(p + i * 4 + 0x24) = 0;
        PRINTSYS_QUE_Clear(*(struct PrintSys **)(p + i * 4 + 0x34));
        BMP_WIN_Delete(*(struct Descriptor **)(p + i * 4 + 0x14));
    }
    for (i = 0; i < 2; i++) BMP_WIN_Delete(*(struct Descriptor **)(p + i * 4 + 0x44));
}
