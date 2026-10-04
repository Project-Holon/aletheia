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
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef struct {int handle;unsigned char active;unsigned char pad[3];} Entry;
extern void func_0201C4E4(int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern int func_0201C6C4(int,int);
extern void func_02045334(struct Descriptor *d);
void func_0220B0B0(Entry *p,int b,unsigned n)
{
    unsigned i;
    func_0201C4E4(b);
    for(i=0;i<n;i++) {
        if(p[i].active && func_0201C6C4(b,(int)func_02045770((struct Descriptor *)p[i].handle))==0) {
            func_02045334((struct Descriptor *)p[i].handle);
            p[i].active=0;
        }
    }
}
