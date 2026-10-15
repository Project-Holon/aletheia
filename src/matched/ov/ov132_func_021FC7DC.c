/*
 * unit: yes
 * function: MUS_COMM_FUNC_WaitSessionNull, MUS_COMM_FUNC_Task
 * address: 0x021FC7DC
 * packet: pkt_ov132_021FC7DC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUS_COMM_FUNC_Update 0x021FCAA8 thumb ov132
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern int GFL_NET_IsSessionNull(void);
extern u32 func_020307B0(void *p);
extern void MUS_COMM_FUNC_Update(char *);
int MUS_COMM_FUNC_WaitSessionNull(int unused,int unused1,void *p) { if(GFL_NET_IsSessionNull()==1) {func_020307B0(p);return 1;} return 0; }
void MUS_COMM_FUNC_Task(int unused,int unused1,char *p) { MUS_COMM_FUNC_Update(p); }
