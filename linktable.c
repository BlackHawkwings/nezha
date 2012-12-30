
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  linktabe.h                             */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :  LinkTable                              */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/12/30                             */
/*  DESCRIPTION           :  interface of Link Table                */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/12/30
 *
 */


#include"linktable.h"
#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE (-1)

/*
 * Create a LinkTable
 */
tLinkTable * CreateLinkTable()
{
	tLinkTable * pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	if(pLinkTable == NULL)
	{
		return NULL;
    }
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
	return pLinkTable;
}
/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
    }
	while(pLinkTable->pHead != NULL)
	{
		tLinkTableNode * p = pLinkTable->pHead;
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		pLinkTable->SumOfNode -= 1 ;
		free(p);
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
	free(pLinkTable);
	return SUCCESS;		
}
/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
    }
	pNode->pNext = NULL;
	if(pLinkTable->pHead == NULL)
	{
		pLinkTable->pHead = pNode;
	}
	if(pLinkTable->pTail == NULL)
	{
		pLinkTable->pTail = pNode;
	}
	else
	{
		pLinkTable->pTail->pNext = pNode;
		pLinkTable->pTail = pNode;
	}
	pLinkTable->SumOfNode += 1 ;
	return SUCCESS;		
}
/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
    }
    if(pLinkTable->pHead == pNode)
    {
        pLinkTable->pHead = pLinkTable->pHead->pNext;
    	pLinkTable->SumOfNode -= 1 ;
    	if(pLinkTable->SumOfNode == 0)
    	{
    		pLinkTable->pTail = NULL;	
    	}
    	return SUCCESS;
    }
    tLinkTableNode * pTempNode = pLinkTable->pHead;
	while(pTempNode != NULL)
    {    
		if(pTempNode->pNext == pNode)
		{
		    pTempNode->pNext = pTempNode->pNext->pNext;
    		pLinkTable->SumOfNode -= 1 ;
    		if(pLinkTable->SumOfNode == 0)
    		{
    			pLinkTable->pTail = NULL;	
    		}
    		return SUCCESS;				    
		}
		pTempNode = pTempNode->pNext;
	}
	return FAILURE;		
}

/*
 * Search a LinkTableNode from LinkTable
 * tLinkTableNode * CmpFn(tLinkTable *pLinkTable);
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * CmpFn(tLinkTable *pLinkTable))
{
    if(pLinkTable == NULL || CmpFn == NULL)
	{
		return NULL;
    }
    return CmpFn(pLinkTable);
}

/*
 * get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
	{
		return NULL;
    }    
	return pLinkTable->pHead;
}

/*
 * get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return NULL;
    }
    tLinkTableNode * pTempNode = pLinkTable->pHead;
	while(pTempNode != NULL)
    {    
		if(pTempNode == pNode)
        {
    		return pTempNode->pNext;				    
		}
		pTempNode = pTempNode->pNext;
	}
	return NULL;
}

