/*
 * function: func_021F2938
 * address:  0x021F2938
 * packet:   pkt_ov107_021F2938
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ReloadCache (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   func_02077EB8 0x02077EB8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02075E04 0x02075E04 arm
 *   func_020788AC 0x020788AC arm
 *   func_02078964 0x02078964 arm
 *   func_02078B70 0x02078B70 arm
 *   func_02078A80 0x02078A80 arm
 *   g_021F6E4C 0x021F6E4C data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u32 src;
    u32 len;
    u8 *ptr;
    u32 state;
} CacheInfo;

typedef struct {
    u32 lifetime;
    u32 recent;
    CacheInfo *p_list;
    u32 size;
    char arc_name[4];
    u32 arc_name_len;
    void *arc_pointer;
} CacheList;

typedef struct {
    void *next;
    u32 busy;
    void *task;
    void *callback;
    u32 param[4];
} TaskInfo;

typedef struct {
    char pad[0x1e0];
    u32 ntr_off;
    u32 ntr_len;
    u32 ltd_off;
    u32 ltd_len;
} RomHeader;

extern char g_021F6E4C[];

extern void *func_02077EB8(char *name, int name_len);
extern int func_02085D3C(void);
extern RomHeader *func_02075E04(void);
extern void func_020788AC(void *file);
extern int func_02078964(void *file, void *arc, u32 top, u32 bottom, u32 id);
extern long func_02078B70(void *file, void *buffer, long length);
extern int func_02078A80(void *file);

void func_021F2938(TaskInfo *p_task)
{
    CacheInfo *p_info;
    CacheList *p_list;
    u32 file[18];
    void *arc;
    u32 length;
    RomHeader *header;
    u32 boundary_ntr;
    u32 boundary_ltd;

    p_list = (CacheList *)p_task->param[1];
    p_info = (CacheInfo *)p_task->param[0];
    length = p_info->len;
    arc = func_02077EB8(p_list->arc_name, p_list->arc_name_len);
    if (arc == 0) {
        arc = p_list->arc_pointer;
    }
    if (func_02085D3C() && arc == func_02077EB8(g_021F6E4C, 3)) {
        header = func_02075E04();
        boundary_ntr = header->ntr_off + header->ntr_len;
        boundary_ltd = header->ltd_off + header->ltd_len;
        if (p_info->src < boundary_ntr && p_info->src + length > boundary_ntr) {
            length = boundary_ntr - p_info->src;
        } else if (p_info->src < boundary_ltd && p_info->src + length > boundary_ltd) {
            length = boundary_ltd - p_info->src;
        }
    }
    func_020788AC(file);
    if (func_02078964(file, arc, p_info->src, p_info->src + length, 0xffffffff)) {
        if (length == func_02078B70(file, p_info->ptr, length)) {
            p_info->state = 2;
        }
        func_02078A80(file);
    }
    if (p_info->state != 2) {
        p_info->src = 0;
        p_info->state = 2;
    }
}
