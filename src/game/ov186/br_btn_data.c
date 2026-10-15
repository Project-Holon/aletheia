/*
 * file:     br_btn_data.c
 * unit:     yes
 * function: BR_BTN_DATA_Create, BR_BTN_DATA_Delete, BR_BTN_DATA_Fill, BR_BTN_DATA_GetRow, BR_BTN_DATA_GetSectionCount, BR_BTN_DATA_GetMaxSectionCount, BR_BTN_DATA_GetRowField, BR_BTN_DATA_CreateLabel
 * address:  0x021FB5E4
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, ov186_func_02200228.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0  0x020307B0  arm
 *   func_02045EC0 0x02045EC0 arm
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D28 0x02200D28 data a1
 *   d_02200D38 0x02200D38 data a1
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 */
#include "br_types.h"

struct WordSet;
struct MsgBank;
struct U16Vec;

extern void STRBUF_Delete(struct U16Vec *vec);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *, int, int);

extern u32 func_020307B0(void *p);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern struct WordSet *GF_FONT_Create_EC64(unsigned int heapId);

extern void WORDSET_SetSlotTag(struct WordSet *p, unsigned int i, const void *src, unsigned int n, unsigned int f, unsigned int c);

extern u16 STRBUF_GetLength(struct U16Vec *vec);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

void *BR_BTN_DATA_Create(int *configPtr, int heapId);

void BR_BTN_DATA_Delete(void *table);

void BR_BTN_DATA_Fill(struct BrBtnTable *table);

void *BR_BTN_DATA_GetRow(struct BrBtnTable *table, int section, unsigned item);

unsigned short BR_BTN_DATA_GetSectionCount(void *table, int section);

unsigned BR_BTN_DATA_GetMaxSectionCount(void *table);

int BR_BTN_DATA_GetRowField(void *record, int fieldIndex);

void *BR_BTN_DATA_CreateLabel(unsigned *const *wordSetSrc, void *record, struct MsgBank *archive, unsigned short heapId);

extern const struct BrBtnSection d_022007F0[];

extern char d_02200D28[];

extern char d_02200D38[];

void *BR_BTN_DATA_Create(int *configPtr, int heapId)
{
    int total = 0;
    int i;
    int *table;
    for (i = 0; i < 12; i++) total += d_022007F0[i].count;
    table = func_02030734(heapId, total * 24 + 4, 0, d_02200D28, 0x429);
    MI_CpuFill8(table, 0, total * 24 + 4);
    *table = *configPtr;
    BR_BTN_DATA_Fill((struct BrBtnTable *)table);
    return table;
}

void BR_BTN_DATA_Delete(void *table) { func_020307B0(table); }

void BR_BTN_DATA_Fill(struct BrBtnTable *table)
{
    int section;
    unsigned count;
    const struct BrBtnTemplate *templates;
    unsigned index;
    unsigned item;
    unsigned total = 0;
    int *config = (int *)table->config;
    struct BrBtnTemplate *row;
    for (section = 0; section < 12; section++) {
        count = d_022007F0[section].count;
        templates = d_022007F0[section].records;
        for (item = 0; item < count; item++) {
            row = (struct BrBtnTemplate *)((char *)table + total * 24 + 4);
            *row = templates[item];
            switch (row->kind) {
            case 1: row->enabled = config[0]; break;
            case 2: case 3: case 4:
                index = row->kind - 2;
                if (index >= 4) func_02034714(d_02200D38, 0, d_02200D38);
                row->enabled = config[index + 1];
                if (row->enabled) row->msgId = 26;
                break;
            case 5: row->enabled = config[20]; break;
            case 0: default: row->enabled = 1; break;
            }
            total++;
        }
    }
}

void *BR_BTN_DATA_GetRow(struct BrBtnTable *table, int section, unsigned item)
{
    int i;
    int total;
    if (section >= 12) func_02034714(d_02200D38, 0, d_02200D38);
    if (item >= d_022007F0[section].count) func_02034714(d_02200D38, 0, d_02200D38);
    total = 0;
    for (i = 0; i < section; i++) total += d_022007F0[i].count;
    return &table->records[total + item];
}

unsigned short BR_BTN_DATA_GetSectionCount(void *table, int section) { if(section>=12)func_02034714(d_02200D38,0,d_02200D38);return d_022007F0[section].count; }

unsigned BR_BTN_DATA_GetMaxSectionCount(void *table) { unsigned best=0;int section;for(section=0;section<12;section++){if(best<BR_BTN_DATA_GetSectionCount(table,section)) best=BR_BTN_DATA_GetSectionCount(table,section);}return best; }

int BR_BTN_DATA_GetRowField(void *record,int fieldIndex) { if(fieldIndex>=12)func_02034714(d_02200D38,0,d_02200D38);return ((u16 *)record)[fieldIndex]; }

void *BR_BTN_DATA_CreateLabel(unsigned *const *wordSetSrc,void *record,struct MsgBank *archive,unsigned short heapId)
{
    int kind,index,hasWordSet;
    void *wordSet,*src,*result;
    kind=BR_BTN_DATA_GetRowField(record,11);
    hasWordSet=0;
    if(kind>=1 && kind<=4){index=kind-1;hasWordSet=1;}
    if(hasWordSet){
        if((*wordSetSrc)[index]!=0){
            wordSet=GF_FONT_Create_EC64((unsigned short)((heapId&0x7fff)|0x8000));
            WORDSET_SetSlotTag(wordSet,0,(const void *)((*wordSetSrc+index)[4]),(*wordSetSrc+index)[8],1,2);
            src=func_02045EC0(archive,(int)BR_BTN_DATA_GetRowField(record,3));
            result=STRBUF_Create(STRBUF_GetLength(src)+7,heapId);
            WORDSET_CopyTaggedText(wordSet,result,src);
            WORDSET_DeleteStrbufED04(wordSet);
            STRBUF_Delete(src);
        }else{
            result=func_02045EC0(archive,(int)BR_BTN_DATA_GetRowField(record,3));
        }
    }else{
        result=func_02045EC0(archive,(int)BR_BTN_DATA_GetRowField(record,3));
    }
    return result;
}
