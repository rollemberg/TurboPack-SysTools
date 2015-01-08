﻿// CodeGear C++Builder
// Copyright (c) 1995, 2014 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StDict.pas' rev: 28.00 (Windows)

#ifndef StdictHPP
#define StdictHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <StConst.hpp>	// Pascal unit
#include <StBase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stdict
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStDictNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TStDictNode : public Stbase::TStNode
{
	typedef Stbase::TStNode inherited;
	
protected:
	TStDictNode* dnNext;
	System::UnicodeString dnName;
	System::UnicodeString __fastcall GetName(void);
	
public:
	__fastcall TStDictNode(const System::UnicodeString Name, void * AData);
	__fastcall virtual ~TStDictNode(void);
	__property System::UnicodeString Name = {read=GetName};
public:
	/* TStNode.Create */ inline __fastcall virtual TStDictNode(void * AData) : Stbase::TStNode(AData) { }
	
};

#pragma pack(pop)

typedef System::StaticArray<TStDictNode*, 536870911> TSymbolArray;

typedef TSymbolArray *PSymbolArray;

typedef int __fastcall (*TDictHashFunc)(const System::AnsiString S, int Size);

class DELPHICLASS TStDictionary;
class PASCALIMPLEMENTATION TStDictionary : public Stbase::TStContainer
{
	typedef Stbase::TStContainer inherited;
	
protected:
	int FHashSize;
	Stbase::TStringCompareFunc FEqual;
	TDictHashFunc FHash;
	Stbase::TStStringCompareEvent FOnEqual;
	TSymbolArray *dySymbols;
	bool dyIgnoreDups;
	void __fastcall dySetEqual(Stbase::TStringCompareFunc E);
	void __fastcall dySetHash(TDictHashFunc H);
	void __fastcall dySetHashSize(int Size);
	void __fastcall dyFindNode(const System::UnicodeString Name, int &H, TStDictNode* &Prev, TStDictNode* &This);
	
public:
	__fastcall virtual TStDictionary(int AHashSize);
	__fastcall virtual ~TStDictionary(void);
	DYNAMIC void __fastcall LoadFromStream(System::Classes::TStream* S);
	DYNAMIC void __fastcall StoreToStream(System::Classes::TStream* S);
	virtual void __fastcall Clear(void);
	virtual int __fastcall DoEqual(const System::UnicodeString String1, const System::UnicodeString String2);
	bool __fastcall Exists(const System::UnicodeString Name, void * &Data);
	void __fastcall Add(const System::UnicodeString Name, void * Data);
	void __fastcall Delete(const System::UnicodeString Name);
	void __fastcall GetItems(System::Classes::TStrings* S);
	void __fastcall SetItems(System::Classes::TStrings* S);
	void __fastcall Update(const System::UnicodeString Name, void * Data);
	bool __fastcall Find(void * Data, System::UnicodeString &Name);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Join(TStDictionary* D, bool IgnoreDups);
	TStDictNode* __fastcall Iterate(Stbase::TIterateFunc Action, void * OtherData);
	int __fastcall BinCount(int H);
	__property Stbase::TStringCompareFunc Equal = {read=FEqual, write=dySetEqual};
	__property TDictHashFunc Hash = {read=FHash, write=dySetHash};
	__property int HashSize = {read=FHashSize, write=dySetHashSize, nodefault};
	__property Stbase::TStStringCompareEvent OnEqual = {read=FOnEqual, write=FOnEqual};
public:
	/* TStContainer.CreateContainer */ inline __fastcall TStDictionary(Stbase::TStNodeClass NodeClass, int Dummy) : Stbase::TStContainer(NodeClass, Dummy) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall AnsiELFHashText(const System::AnsiString S, int Size);
extern DELPHI_PACKAGE int __fastcall AnsiELFHashStr(const System::AnsiString S, int Size);
extern DELPHI_PACKAGE int __fastcall AnsiHashStr(const System::AnsiString S, int Size);
extern DELPHI_PACKAGE int __fastcall AnsiHashText(const System::AnsiString S, int Size);
}	/* namespace Stdict */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STDICT)
using namespace Stdict;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdictHPP