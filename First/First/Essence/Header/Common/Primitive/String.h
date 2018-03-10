#ifndef ESSENCE_COMMON_PRIMITIVE_STRING_H
#define ESSENCE_COMMON_PRIMITIVE_STRING_H
#include "Base\IPrimitive.h"

namespace essence { namespace primitive {

class CString : public IPrimitive
{

public:
#if _UNICODE
	typedef wchar_t unitType;
#else
	typedef char unitType;
#endif

public:
	static const CString Empty;
public:
	CString();
	CString( const CString& );
	CString(unitType*);
	CString( CString&& ) noexcept;
	~CString();


	/**
	* 第一引数の文字列を第二引数の文字列に置き換えた文字列を返す。
	*/
	CString Replace( const CString&, const CString& );

	/**
	* 現在の値から引数の文字列を削除した文字列を返す
	*/

	CString Substring( const CString& );

	/**
	* 文字列の長さ
	*/
	int Length() const;

	/**
	* 値の取得
	*/
	unitType* Value()const;

	/**
	* タイプの取得
	*/
	EType Type()override;


public:
	/**
	* オペレーターのオーバーロード
	*/

	/**
	* 引数の文字列との等しいか比較
	*/
	bool operator == (unitType*);

	/**
	* 引数の文字列との等しくないか比較
	*/
	bool operator != (unitType*);

	/**
	* 引数の文字列との等しくないか比較
	*/
	bool operator == (CString&);

	/**
	* 引数の文字列との等しくないか比較
	*/
	bool operator != (CString&);

	/**
	* 代入
	*/
	CString& operator = (unitType*);

	/**
	* 文字列の連結
	*/
	CString& operator += (unitType*);
	CString& operator += (CString&);
	CString operator + (unitType*);
	CString operator + (CString&);

private:
	unitType* m_value;
};

}}
#endif
