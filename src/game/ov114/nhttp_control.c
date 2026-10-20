/*
 * file:     nhttp_control.c
 * unit:     yes
 * function: addHdrList, incAscii, checkTagPost, NHTTPi_getHdrFromList, NHTTPi_AddRequestHeaderField, NHTTPi_AddRequestPostDataAscii
 * address:  0x021BAA1C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_compareToken  0x021BA590  arm  ov114
 *   NHTTPi_alloc  0x021BA820  arm  ov114
 *   NHTTPi_SetError  0x021BA874  arm  ov114
 *   NHTTPi_memfind 0x021BA690 arm ov114
 *   g_021CDFC8 0x021CDFC8 data
 *   NHTTPi_strlen 0x021BA118 arm ov114
 */
#include "nhttp_types.h"

#include "nhttp_stdlib_ntr.h"
#include "nhttp_bgnend.h"
int addHdrList(NHTTPi_DATALIST **head_pp, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
char incAscii(u8 c);
int checkTagPost(NHTTPReq *req_p, char *value_p, unsigned long length);
NHTTPi_DATALIST *NHTTPi_getHdrFromList(NHTTPi_DATALIST **head_pp);
int NHTTPi_AddRequestHeaderField(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
int NHTTPi_AddRequestPostDataAscii(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p);
extern char g_021CDFC8[];



int addHdrList(NHTTPi_DATALIST **head_pp, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p)
{
    NHTTPi_DATALIST *node_p = *head_pp;
    int found = 0;
    NHTTPi_DATALIST *match_p;
    NHTTPi_DATALIST *newNode_p;

    if (node_p != 0) {
        match_p = node_p;
        if (NHTTPi_compareToken(label_p, match_p->name) != 0) {
            match_p = match_p->next;
            while (match_p != *head_pp) {
                if (NHTTPi_compareToken(label_p, match_p->name) == 0) {
                    found = 1;
                    break;
                }
                match_p = match_p->next;
            }
        } else {
            found = 1;
        }
    }

    if (found != 0) {
        match_p->data = value_p;
    } else {
        newNode_p = NHTTPi_alloc(0x18, 4);
        if (newNode_p == 0) {
            NHTTPi_SetError(bgnEndInfo_p, 1);
            return 0;
        }
        newNode_p->name = label_p;
        newNode_p->data = value_p;
        newNode_p->len = 0;
        newNode_p->isBinary = 0;
        if (*head_pp == 0) {
            newNode_p->next = newNode_p;
            newNode_p->prev = newNode_p;
            *head_pp = newNode_p;
        } else {
            newNode_p->prev = (*head_pp)->prev;
            newNode_p->next = *head_pp;
            (*head_pp)->prev->next = newNode_p;
            (*head_pp)->prev = newNode_p;
        }
    }
    return 1;
}



/*
 * Successor of a character on the '0'..'z' wheel, wrapping at the gaps.
 * Returning 'signed char' is what puts the single shared sign-extending
 * epilogue at 0x021BAB4C after the value is assigned, not returned early.
 */
char incAscii(u8 c)
{
    c = (c + 1) & 0xff;
    if (c == 0x7b)
        c = 0x30;
    else if (c == 0x5b)
        c = 0x61;
    else if (c == 0x3a)
        c = 0x41;
    return (signed char)c;
}



int checkTagPost(NHTTPReq *req_p, char *value_p, unsigned long length)
{
    char c;
    int n;

    if (NHTTPi_memfind((signed char *)value_p, length, (signed char *)(&req_p->multipartBound[2]), 0x12) < 0) {
        return 1;
    }
    for (n = 0x13; n >= 2; n--) {
        NHTTPReq *tp = (NHTTPReq *)((char *)req_p + n);
        char target;
        c = tp->multipartBound[0];
        target = g_021CDFC8[n];
        while (1) {
            c = incAscii(c);
            tp->multipartBound[0] = c;
            if (c == target) {
                break;
            }
            if (NHTTPi_memfind((signed char *)value_p, length, (signed char *)(&req_p->multipartBound[2]), 0x12) < 0) {
                return 1;
            }
        }
    }
    return 0;
}



NHTTPi_DATALIST *NHTTPi_getHdrFromList(NHTTPi_DATALIST **head_pp)
{
    NHTTPi_DATALIST *node_p = *head_pp;

    if (node_p != 0)
    {
        if (node_p == node_p->prev)
        {
            *head_pp = 0;
        }
        else
        {
            node_p->prev->next = node_p->next;
            node_p->next->prev = node_p->prev;
            *head_pp = node_p->next;
        }
    }
    return node_p;
}



/*
 * Adds a header to the request's header list unless the request has started.
 */
int NHTTPi_AddRequestHeaderField(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p)
{
    if (req_p->isStarted != 0)
        return 0;
    return addHdrList(&req_p->hdrlist_p, bgnEndInfo_p, label_p, value_p);
}



int NHTTPi_AddRequestPostDataAscii(NHTTPReq *req_p, NHTTPBgnEndInfo *bgnEndInfo_p, char *label_p, char *value_p)
{
    int rc = 0;
    unsigned long length = 0;

    if (req_p->isStarted != 0) {
        return 0;
    }
    if (req_p->isRawData != 0) {
        return 0;
    }
    if (value_p != 0) {
        length = NHTTPi_strlen(value_p);
    }
    if (checkTagPost(req_p, value_p, length) != 0) {
        rc = addHdrList(&req_p->datalist_p, bgnEndInfo_p, label_p, value_p);
        if (rc != 0) {
            req_p->datalist_p->prev->len = length;
        }
    }
    return rc;
}
