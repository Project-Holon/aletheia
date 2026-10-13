/*
 * function: func_0220B0B0
 * address: 0x0220B0B0
 * packet: pkt_ov196_0220B0B0
 * region: ov196
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: intended code is 66 bytes; the handed tail is zero alignment and b_sap_ptool.c string data, not follower code.
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
typedef struct {int handle;unsigned char active;unsigned char pad[3];} Entry;
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void func_0220B0B0(Entry *p,int b,unsigned n)
{
    unsigned i;
    PRINTSYS_QUE_Main((struct PrintSys *)b);
    for(i=0;i<n;i++) {
        if(p[i].active && func_0201C6C4((struct PrintSys *)b,(void *)((int)func_02045770((struct Descriptor *)p[i].handle)))==0) {
            BMP_WIN_TransferChars((struct Descriptor *)p[i].handle);
            p[i].active=0;
        }
    }
}
