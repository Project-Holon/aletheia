/*
 * function: REPORT_EVENT_Free
 * address:  0x02169E0C
 * packet:   pkt_02169E0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   REPORT_EVENT_DeleteMenuResources  0x0216A128  thumb  ov010
 *   REPORT_EVENT_DeleteMessageWindow  0x02169E98  thumb  ov010
 *   func_0201C4C0  0x0201C4C0  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00029.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int REPORT_EVENT_DeleteMenuResources();
extern int REPORT_EVENT_DeleteMessageWindow(char *p);
extern int func_0201C4C0();
extern int APP_KEYCURSOR_Delete(int a0);
extern int TCBL_Destroy();
extern int STRBUF_Delete();
extern int MSGDATA_Delete();
extern u32 func_020307B0(void *p);

int REPORT_EVENT_Free(char *a0)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)REPORT_EVENT_DeleteMenuResources(a0);
loc_02169E14:
a0 = (char *)(t4 + 0);
    a0 = (char *)REPORT_EVENT_DeleteMessageWindow(a0);
loc_02169E1A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f14);
    a0 = (char *)func_0201C4C0(a0);
loc_02169E22:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f1C);
    a0 = (char *)APP_KEYCURSOR_Delete((int)a0);
loc_02169E2A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)((char *)a0))->f0);
    a0 = (char *)TCBL_Destroy(a0);
loc_02169E32:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f18);
    a0 = (char *)STRBUF_Delete(a0);
loc_02169E3A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f4);
    a0 = (char *)MSGDATA_Delete(a0);
loc_02169E42:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
    a0 = (char *)func_020307B0(a0);
loc_02169E48:
    return (int)a0;}
