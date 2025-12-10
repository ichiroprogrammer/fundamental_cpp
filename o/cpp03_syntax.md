<!-- ./md/cpp03_syntax.md -->
# レガシーC++ <a id="SS_2"></a>
このドキュメントでのレガシーC++とはC++03までのC++を指す。
従って、C++から導入された以下のシンタックスや標準ライブラリは本章の対象外となる。

- [スマートポインタ](stdlib_and_concepts.md#SS_9_6)(ダイナミックメモリアロケーションで生成されたオブジェクトの自動開放)
- [rvalueリファレンス](core_lang_spec.md#SS_8_8_2)(右辺値参照)/ [moveセマンティクス](cpp_idioms.md#SS_10_5_3)
- 範囲forループ
- ラムダ式
- auto/decltypeによる型推論
- テンプレートの強化(パラメータパック、SFINAE強化等)

レガシーC++はC90のシンタックスと以下のようなシンタックスやライブラリから形作られる。
なお、C90のシンタックスについての知識が不十分な場合、
本ドキュメントを読み進める前に、
[プログラミング言語C](https://www.amazon.co.jp/%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E8%A8%80%E8%AA%9EC-%E7%AC%AC2%E7%89%88-ANSI%E8%A6%8F%E6%A0%BC%E6%BA%96%E6%8B%A0-B-W-%E3%82%AB%E3%83%BC%E3%83%8B%E3%83%8F%E3%83%B3/dp/4320026926/ref=sr_1_3?dib=eyJ2IjoiMSJ9.9Y_CW98q5Eu6U4fMPe6uvEk0WTyCyc9HJeKOSU9VvnvGjHj071QN20LucGBJIEps.W4xuvhyS-yLi38GF8W6XUxu0IowUfHtbcHdfKVWPa8s&dib_tag=se&qid=1756356689&refinements=p_27%3AB.W.+%E3%82%AB%E3%83%BC%E3%83%8B%E3%83%8F%E3%83%B3&s=books&sr=1-3&text=B.W.+%E3%82%AB%E3%83%BC%E3%83%8B%E3%83%8F%E3%83%B3)
の熟読を薦める。

- [クラス](cpp03_syntax.md#SS_2_1)関連
- [リファレンス](--)(参照)
- テンプレート
- 名前空間
- 例外処理
- RTTI
- 追加された型(bool, wchar_t)
- キャスト
- 演算子
    - ::, `.*`, `->*`
    - new, delete
    - 演算子オーバーロード(operator 構文)

___

__インデックス__

&emsp;&emsp; [クラス](cpp03_syntax.md#SS_2_1)  
&emsp;&emsp;&emsp; [メンバ関数](cpp03_syntax.md#SS_2_1_1)  
&emsp;&emsp;&emsp; [コンストラクタ](cpp03_syntax.md#SS_2_1_2)  
&emsp;&emsp;&emsp; [メンバ変数の初期化リスト](cpp03_syntax.md#SS_2_1_3)  
&emsp;&emsp;&emsp; [デストラクタ](cpp03_syntax.md#SS_2_1_4)  
&emsp;&emsp;&emsp; [アクセス指定子](cpp03_syntax.md#SS_2_1_5)  
&emsp;&emsp;&emsp; [アクセス指定子の使用例](cpp03_syntax.md#SS_2_1_6)  
&emsp;&emsp;&emsp; [staticメンバ](cpp03_syntax.md#SS_2_1_7)  
&emsp;&emsp;&emsp; [コピーコンストラクタ/コピー代入演算子](cpp03_syntax.md#SS_2_1_8)  
&emsp;&emsp;&emsp; [this](cpp03_syntax.md#SS_2_1_9)  
&emsp;&emsp;&emsp; [constメンバ関数](cpp03_syntax.md#SS_2_1_10)  
&emsp;&emsp;&emsp; [constメンバ変数](cpp03_syntax.md#SS_2_1_11)  
&emsp;&emsp;&emsp; [フレンド宣言](cpp03_syntax.md#SS_2_1_12)  
&emsp;&emsp;&emsp; [等値比較演算子](cpp03_syntax.md#SS_2_1_13)  
&emsp;&emsp;&emsp; [Personのリファクタリング](cpp03_syntax.md#SS_2_1_14)  
&emsp;&emsp;&emsp; [演算子オーバーロード](cpp03_syntax.md#SS_2_1_15)  

&emsp;&emsp; [オーバーロード](cpp03_syntax.md#SS_2_2)  
&emsp;&emsp;&emsp; [オーバーロードの使用例](cpp03_syntax.md#SS_2_2_1)  
&emsp;&emsp;&emsp; [オーバーロード解決の規則](cpp03_syntax.md#SS_2_2_2)  
&emsp;&emsp;&emsp; [オーバーロードと型変換/曖昧性](cpp03_syntax.md#SS_2_2_3)  

&emsp;&emsp; [デフォルト引数](cpp03_syntax.md#SS_2_3)  
&emsp;&emsp; [テンプレート](cpp03_syntax.md#SS_2_4)  
&emsp;&emsp;&emsp; [クラステンプレート](cpp03_syntax.md#SS_2_4_1)  
&emsp;&emsp;&emsp; [関数テンプレート](cpp03_syntax.md#SS_2_4_2)  

&emsp;&emsp; [名前空間](cpp03_syntax.md#SS_2_5)  
&emsp;&emsp; [標準ライブラリ](cpp03_syntax.md#SS_2_6)  
&emsp;&emsp;&emsp; [std::stringの使用例 ](cpp03_syntax.md#SS_2_6_1)  
&emsp;&emsp;&emsp; [入出力(stream)](cpp03_syntax.md#SS_2_6_2)  
&emsp;&emsp;&emsp; [コンテナ](cpp03_syntax.md#SS_2_6_3)  

&emsp;&emsp; [継承](cpp03_syntax.md#SS_2_7)  
&emsp;&emsp;&emsp; [public継承](cpp03_syntax.md#SS_2_7_1)  
&emsp;&emsp;&emsp; [protectd継承](cpp03_syntax.md#SS_2_7_2)  
&emsp;&emsp;&emsp; [private継承](cpp03_syntax.md#SS_2_7_3)  
&emsp;&emsp;&emsp; [派生](cpp03_syntax.md#SS_2_7_4)  
&emsp;&emsp;&emsp; [オーバーライド](cpp03_syntax.md#SS_2_7_5)  

&emsp;&emsp; [new/delete](cpp03_syntax.md#SS_2_8)  
&emsp;&emsp;&emsp; [new演算子](cpp03_syntax.md#SS_2_8_1)  
&emsp;&emsp;&emsp; [delete演算子](cpp03_syntax.md#SS_2_8_2)  
&emsp;&emsp;&emsp; [new[]演算子](cpp03_syntax.md#SS_2_8_3)  
&emsp;&emsp;&emsp; [delete[]演算子](cpp03_syntax.md#SS_2_8_4)  
  
  

[インデックス](fundamental_intro.md#SS_1_3)に戻る。  

___


## クラス <a id="SS_2_1"></a>
この節ではクラスの概念とシンタックスを解説する。
C++におけるクラスは、C90でも規定されている`struct`と、
C++で規定されている`class`によってユーザが定義する型である。
C++での`struct`と`class`は以下の点について異なるが、概念としては同一であると考えられる。

* [アクセス指定子](cpp03_syntax.md#SS_2_1_5)無しでのメンバへのアクセス
    - structではデフォルトが`public`
    - classではデフォルトが`private`

* [アクセス指定子](cpp03_syntax.md#SS_2_1_5)無しでの継承
   - `struct`からの継承はデフォルトで`public`
   - `class`からの継承はデフォルトで`private`

すなわち、両者の違いはデフォルトのアクセス指定にとどまり、機能的な差は存在しない。
したがって、利用者は設計意図に応じてstructまたはclassを選択すればよい。
一般的には、データ構造的な性格が強い単純な型にはstructを、
カプセル化を意識した抽象化された型にはclassを用いる慣習がある。

Cでの`struct`は以下の点において、C++での`struct`と異なる。

* [メンバ関数](cpp03_syntax.md#SS_2_1_1)の定義
* デフォルトのメンバ変数の初期化(そのメンバ変数がデフォルトコンストラクタを持っている場合)
* [アクセス指定子](cpp03_syntax.md#SS_2_1_5)
* [継承](cpp03_syntax.md#SS_2_7)

### メンバ関数 <a id="SS_2_1_1"></a>
メンバ関数とは、クラスに属し、そのインスタンスを通じて呼び出される関数である。
インスタンスの状態を操作したり、外部からの要求に応じて振る舞いを定義するために使用される。

Cとの比較の例を用いて、メンバ関数を導入する。
まずは、以下の構造体と関数の組み合わせのコード例について見ていこう。

```cpp
    //  example/cpp03_syntax/class_00_ut.cpp 9

    struct Person {
        char const* family_name;
        char const* first_name;
        uint32_t    height_cm;  // 身長 (cm単位と仮定)
        uint32_t    weight_kg;  // 体重 (kg単位と仮定)
    };

    uint32_t calc_bmi(struct Person const* person)
    {
        if ((person != NULL) && (person->height_cm == 0)) {
            return 0;
        }

        // BMI = 体重(kg) / (身長(m))^2
        // 身長をcmからmに変換: height_cm / 100
        // BMI = weight_kg / ((height_cm / 100.0)^2)
        // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

        uint32_t bmi = (person->weight_kg * 10000) / (person->height_cm * person->height_cm);

        return bmi;
    }
```

上記のcalc_bmiはPersonインスタンスからBMIを導き出す関数である。
以下にPersonとcalc_bmiの使用例を示す。

```cpp
    //  example/cpp03_syntax/class_00_ut.cpp 36

    struct Person person = {
        "yamada",  // 姓
        "taro",    // 名
        173,       // 身長cm
        75,        // 体重kg
    };

    uint32_t bmi = calc_bmi(&person);
```

C++では、上記のような場合、メンバ関数を使用して、下記のように記述する。

```cpp
    //  example/cpp03_syntax/class_01_ut.cpp 9

    struct Person {
        char const* family_name;
        char const* first_name;
        uint32_t    height_cm;       // 身長 (cm単位と仮定)
        uint32_t    weight_kg;       // 体重 (kg単位と仮定)
        uint32_t    calc_bmi(void);  // メンバ関数
    };

    uint32_t Person::calc_bmi(void)  // Personのcalc_bmiの定義
    {
        // BMI = 体重(kg) / (身長(m))^2
        // 身長をcmからmに変換: height_cm / 100
        // BMI = weight_kg / ((height_cm / 100.0)^2)
        // 整数演算で行うため: BMI = (weight_kg * 10000) / (height_cm^2)

        uint32_t bmi = weight_kg * 10000 / (height_cm * height_cm);

        return bmi;
    }
```

なお、Person::calc_bmiは、 calc_bmiがPersonのメンバであることを表す。
Person::calc_bmi()の使用方法は、以下のとおりである。

```cpp
    //  example/cpp03_syntax/class_01_ut.cpp 35

    Person person = { // Cとは異なり、インスタンスの宣言にはstructの記述は不要
        "yamada",  // 姓
        "taro",    // 名
        173,       // 身長cm
        75,        // 体重kg
    };

    uint32_t bmi = person.calc_bmi();
```

上記例でのPersonのインスタンスpersonは適切に初期化されているが、
Person::height_cmを0で初期されたpersonはcalc_bmiに0除算を発生させてしまう。
クラスの制限に適合するインスタンスを生成できるようにするためのシンタックスが、
特殊なメンバ関数である[コンストラクタ](cpp03_syntax.md#SS_2_1_2)である。


Person::calc_bmi()のような一般のメンバ関数以外に用途が限定された以下のような特殊な関数がある。

* [コンストラクタ](cpp03_syntax.md#SS_2_1_2)
* [デストラクタ](cpp03_syntax.md#SS_2_1_4)
* [コピーコンストラクタ/コピー代入演算子](cpp03_syntax.md#SS_2_1_8)


### コンストラクタ <a id="SS_2_1_2"></a>
インスタンス生成時に呼ばれる特別なメンバ関数であり、メンバ変数の初期化やリソース確保を行う。

以下のコードでは、前例のPersonにコンストラクタを定義する。

```cpp
    //  example/cpp03_syntax/class_02_ut.cpp 12

    struct Person {
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        char const* family_name;
        char const* first_name;
        uint32_t    height_cm;       // 身長 (cm単位と仮定)
        uint32_t    weight_kg;       // 体重 (kg単位と仮定)
        uint32_t    calc_bmi(void);  // メンバ関数
    };

    // コンストラクタの定義
    Person::Person(char const* a_family_name, char const* a_first_name, uint32_t a_height_cm, uint32_t a_weight_kg)
    {
        family_name = a_family_name;  //初期化と呼ばれることもあるが、正確には代入
        first_name  = a_first_name;
        height_cm   = a_height_cm;
        weight_kg   = a_weight_kg;

        assert(family_name && first_name);  // コンストラクタはエラーを通知できないので、
        assert(height_cm != 0);             // ここでは不正な引数にはassertで対処
    }
```

コンストラクタが定義されたクラスのインスタンス化は以下のように行う。

```cpp
    //  example/cpp03_syntax/class_02_ut.cpp 39

    Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

    // ASSERT_EQ(person.height_cm, 173);
    // ASSERT_EQ(person.weight_kg, 75);
    ASSERT_STREQ(person.family_name, "yamada");  // 文字列として同値
    ASSERT_STREQ(person.first_name, "taro");     // 文字列として同値
```

### メンバ変数の初期化リスト <a id="SS_2_1_3"></a>
[コンストラクタ](cpp03_syntax.md#SS_2_1_2)のコード例で示したメンバ変数の初期化は、慣習的には初期化と呼ばれるが、
正確にはメンバ変数への値の代入である。
前記したコード例では、メンバ変数の初期化リストを以下のように使用するべきである
([constメンバ変数](cpp03_syntax.md#SS_2_1_11)の初期化を行うためには、初期化リストが必須)。

なお、メンバ変数の初期化順序は、メンバ変数の初期化リストの順とは関係なく、
変数の宣言の順に従うため注意が必要である。
従って、メンバ変数の宣言の順で、初期化リストを並べるのがセオリーとなっている。

```cpp
    //  example/cpp03_syntax/class_02_ut.cpp 67

    struct Person {
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        char const* family_name;
        char const* first_name;
        uint32_t    height_cm;       // 身長 (cm単位と仮定)
        uint32_t    weight_kg;       // 体重 (kg単位と仮定)
        uint32_t    calc_bmi(void);  // メンバ関数
    };

    // コンストラクタの定義
    Person::Person(char const* a_family_name, char const* a_first_name, uint32_t a_height_cm, uint32_t a_weight_kg)
        // メンバ変数の初期化リスト
        // メンバ変数の初期化の順番は、変数の宣言の順番通りに行われる
        : family_name(a_family_name), first_name(a_first_name), height_cm(a_height_cm), weight_kg(a_weight_kg)
    {
        if ((family_name == NULL) || (first_name == NULL)) {
            throw std::invalid_argument("name must be not NULL");  // エラーの通知
        }
        if (height_cm == 0) {
            throw std::logic_error("height_cm must be not zero");  // エラーの通知
        }
    }

```

```cpp
    //  example/cpp03_syntax/class_02_ut.cpp 97

    Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

    ASSERT_EQ(person.height_cm, 173);
    ASSERT_EQ(person.weight_kg, 75);
    ASSERT_STREQ(person.family_name, "yamada");  // 文字列として同値
    ASSERT_STREQ(person.first_name, "taro");     // 文字列として同値

    bool exception_occured = false;

    try {
        Person person_error(NULL, NULL, 0, 75);
    }
    catch (std::logic_error const& logic_error) {  // エクセプションのcatch
        exception_occured = true;
    }

    ASSERT_TRUE(exception_occured);  // エクセプションのthrowの確認

    // gtestでのエクセプションのテスト
    ASSERT_THROW(({ Person person_error("yamada", "taro", 0, 75); }), std::logic_error);
    ASSERT_THROW(({ Person person_error(NULL, "taro", 1, 75); }), std::invalid_argument);
```

コンストラクタは戻り値を持つことはできないため、引数がクラスの制限に収まらない場合、
エラーを返すことができない。そのような場合、
すでに示したコード例のように、[エクセプションのthrow](core_lang_spec.md#SS_8_13_3)によって呼び出し元にエラーを通知することができる。

### デストラクタ <a id="SS_2_1_4"></a>

次の例では前出のPersonに以下の仕様を満たすget_full_name()を追加する。

* ヒープから適切なサイズのメモリを取得して、そのポインタをfull_nameに保存する
* 取得したメモリに、family_nameとfirst_nameを適切にコピーしてフルネームを生成する
* full_nameに保存したポインタを返す

```cpp
    //  example/cpp03_syntax/class_03_ut.cpp 10

    struct Person {
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        char const* family_name;
        char const* first_name;
        char*       full_name;  // 新規メンバ

        uint32_t height_cm;       // 身長 (cm単位と仮定)
        uint32_t weight_kg;       // 体重 (kg単位と仮定)
        uint32_t calc_bmi(void);  // メンバ関数

        char const* get_full_name(void);
    };

    // コンストラクタの定義
    Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
        : family_name(family_name),
          first_name(first_name),
          full_name(NULL),  // 新規に追加されたメンバをNULLで初期化
          height_cm(height_cm),
          weight_kg(weight_kg)
    {
        // コンストラクタの中身は省略
        // ...
    }

    char* make_full_name(char const* family_name, char const* first_name)
    {
        if (!family_name || !first_name) {
            return NULL;
        }

        size_t family_len = strlen(family_name);
        size_t first_len  = strlen(first_name);

        char* full_name = (char*)malloc(family_len + 1 + first_len + 1);  // 姓と名の間に1スペース入れる

        if (!full_name) {
            return NULL;
        }

        strcpy(full_name, family_name);
        full_name[family_len] = ' ';
        strcpy(full_name + family_len + 1, first_name);

        return full_name;
    }

    // 新規関数
    char const* Person::get_full_name(void)
    {
        if (full_name) {  // すでにfull_nameの生成済
            return full_name;
        }

        return full_name = make_full_name(family_name, first_name);
    }
```

クラスを修正した場合、当然それに合わせて単体テストコードも修正が必要である。

```cpp
    //  example/cpp03_syntax/class_03_ut.cpp 82

    Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

    char const* full_name = person.get_full_name();

    ASSERT_STREQ(full_name, "yamada taro");  // 文字列として同値
```

単体テストで示したようにこの関数は想定通り動作するが、メモリーリークを引き起こす。
これに対処するためのメンバ関数が[デストラクタ](cpp03_syntax.md#SS_2_1_4)である。

インスタンス破棄時に呼ばれる特別なメンバ関数であり、リソース解放などの後処理を行う。

以下の例では前節で指摘したメモリーリークのバグをデストラクタを用いて対処する。


```cpp
    //  example/cpp03_syntax/class_04_ut.cpp 11

    struct Person {
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        char const* family_name;
        char const* first_name;
        char*       full_name;  // 新規メンバ

        uint32_t height_cm;       // 身長 (cm単位と仮定)
        uint32_t weight_kg;       // 体重 (kg単位と仮定)
        uint32_t calc_bmi(void);  // メンバ関数

        char const* get_full_name(void);

        ~Person(void);  // デストラクタ
    };

    Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
        : family_name(family_name), first_name(first_name), full_name(NULL),
          height_cm(height_cm), weight_kg(weight_kg)
    {
        // コンストラクタの中身は省略
        // ...
    }

    char* make_full_name(char const* family_name, char const* first_name)
    {
        if (!family_name || !first_name) {
            return NULL;
        }

        size_t family_len = strlen(family_name);
        size_t first_len  = strlen(first_name);

        char* full_name = (char*)malloc(family_len + 1 + first_len + 1);  // 姓と名の間に1スペース入れる

        if (!full_name) {
            return NULL;
        }

        strcpy(full_name, family_name);
        full_name[family_len] = ' ';
        strcpy(full_name + family_len + 1, first_name);

        return full_name;
    }

    char const* Person::get_full_name(void)
    {
        if (full_name) {  // すでにfull_nameの生成済
            return full_name;
        }

        return full_name = make_full_name(family_name, first_name);
    }

    Person::~Person(void)  // デストラクタの定義
    {
        if (full_name) {
            free((void*)full_name);
        }
    }
```
```cpp
    //  example/cpp03_syntax/class_04_ut.cpp 99

    {
        Person person("yamada", "taro", 173, 75);  // オブジェクトの生成

        char const* full_name = person.get_full_name();

        ASSERT_STREQ(full_name, "yamada taro");  // 文字列として同値
    }  // この行でpersonがスコープアウトするためpersonのデストラクタが呼ばれ、
       // personのfull_nameがfreeされる。
```

### アクセス指定子 <a id="SS_2_1_5"></a>

アクセス指定子とは、クラスや構造体のメンバ(データメンバやメンバ関数)に対して、
外部からのアクセスをどの範囲まで許すかを指定する仕組みである。
C++では以下の3種類のアクセス指定子が存在する。

* public
  - どこからでもアクセス可能。
  - クラスの利用者が使用するインターフェース(関数や定数など)を公開する場合に用いる。

* protected
  - クラス自身とその派生クラスからのみアクセス可能。
  - 外部からは直接アクセスできない。
  - 継承関係における拡張を意図した場合に利用される。

* private
  - クラス自身からのみアクセス可能。
  - 派生クラスや外部からは直接アクセスできない。
  - データの隠蔽(カプセル化)を実現するための基本的な指定子。

なお、デフォルトのアクセス指定は次の通りである。

* class：デフォルトはprivate
* struct：デフォルトはpublic

### アクセス指定子の使用例 <a id="SS_2_1_6"></a>
これまで例として使ってきたPersonのメンバ変数は以下のような制約を持つ。

* family_nameとfirst_nameはNULLでなく、文字列リテラル
* full_nameはNULLであるか、family_nameとfirst_nameから生成されるヒープ上の文字列
* height_cmとweight_kgは0でない

これらの制約が外部から変更された場合、Personが正常に動作しないことがある。
このような問題を避けるために、クラスは[アクセス指定子](cpp03_syntax.md#SS_2_1_5)を使用し、
メンバへのアクセスを制御することが一般的である。

これまでクラスは`struct`を使用してきたが、ここで、
[アクセス指定子](cpp03_syntax.md#SS_2_1_5)と`class`を使用し、以下のようにPersonのリファクタリングを行う。

```cpp
    //  example/cpp03_syntax/class_05_ut.cpp 11

    class Person {
    public:
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        uint32_t    calc_bmi(void);  // メンバ関数
        char const* get_full_name(void);

        ~Person(void);  // デストラクタ

    private:  // メンバ変数への外部からのアクセスを禁止する。
        char const* family_name;
        char const* first_name;
        char*       full_name;  // 新規メンバ

        uint32_t height_cm;  // 身長 (cm単位と仮定)
        uint32_t weight_kg;  // 体重 (kg単位と仮定)
    };

    Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
        : family_name(family_name), first_name(first_name), full_name(NULL),
          height_cm(height_cm), weight_kg(weight_kg)
    {
        // コンストラクタの中身は省略
        // ...
    }

    char* make_full_name(char const* family_name, char const* first_name)
    {
        // 関数の中身は変わっていないので省略
        // ...
    }

    char const* Person::get_full_name(void)
    {
        if (full_name) {  // すでにfull_nameの生成済
            return full_name;
        }

        return full_name = make_full_name(family_name, first_name);
    }

    Person::~Person(void)  // デストラクタの定義。
    {
        if (full_name) {
            free((void*)full_name);
        }
    }
```

### staticメンバ <a id="SS_2_1_7"></a>
`static`メンバは、クラスの各インスタンスに属するのではなく、
クラス全体で共有されるメンバを定義するために使用される。

* staticメンバ変数
    - すべてのインスタンスで共通のデータを保持する。
    - 通常のメンバ変数と異なり、オブジェクト生成に依存せず存在する。
    - Cの静的変数と同様に初期化される。

* 静的メンバ関数
    - インスタンスに依存せずに呼び出せる関数。
    - [this](cpp03_syntax.md#SS_2_1_9)ポインタを持たないため、非静的メンバ変数や非静的メンバ関数に直接アクセスできない。
    - クラスのユーティリティ的な操作や、静的メンバ変数の操作に利用される。


前出のPerson::get_full_name()の実装に使用したmake_full_nameは、
以下の例のようにstaticな関数にすることができる。
上記したようにPerson::make_full_name()はメンバ変数に直接アクセスできないため、
通常のメンバ関数に比べて制限が多い分、可読性が向上する。

```cpp
    //  example/cpp03_syntax/class_06_ut.cpp 11

    class Person {
    public:
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        uint32_t    calc_bmi(void);  // メンバ関数
        char const* get_full_name(void);

        ~Person(void);  // デストラクタ

        // make_full_nameをPerson内のstatic関数に変更した
        static char* make_full_name(char const* family_name, char const* first_name);

    private:  // メンバ変数への外部からのアクセスを禁止する
        char const* family_name;
        char const* first_name;
        char*       full_name;

        uint32_t height_cm;  // 身長 (cm単位と仮定)
        uint32_t weight_kg;  // 体重 (kg単位と仮定)
    };

    Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
        : family_name(family_name), first_name(first_name), full_name(NULL),
          height_cm(height_cm), weight_kg(weight_kg)
    {
        // コンストラクタの中身は省略
        // ...
    }

    char* Person::make_full_name(char const* family_name, char const* first_name)
    {
        // 関数の中身は変わっていないので省略
        // ...
    }

    char const* Person::get_full_name(void)
    {
        if (full_name) {  // すでにfull_nameの生成済
            return full_name;
        }

        // return full_name = make_full_name(family_name, first_name);

        // 上記でも問題なくmake_full_nameを呼び出せるが、Personのメンバ関数であることを強調したい場合、
        // 以下のように書いてもよい
        return full_name = Person::make_full_name(family_name, first_name);
    }

    Person::~Person(void)  // デストラクタの定義。
    {
        if (full_name) {
            free((void*)full_name);
        }
    }
```

publicなstaitcメンバへのクラス外でのアクセスには、
下記コードの例のようにクラス名修飾(任意のクラス名Tに対してT::member)がに必要になる。

```cpp
    //  example/cpp03_syntax/class_06_ut.cpp 113

    char* full_name = Person::make_full_name("yamada", "taro");
    //                      ^^^^^ static関数の呼び出しはクラス名修飾が必要

    ASSERT_STREQ(full_name, "yamada taro");  // 文字列として同値
    free((void*)full_name);
```


staticメンバ変数を使用し、さらにPersonに以下のような変更を加える。

* Personのインスタンスの数を数えるstaticなpublicメンバ変数の追加
* Personのコンストラクタ呼び出し時にPerson::full_nameの初期化
* Person::make_full_nameをクラス内部での使用専用にするためにprivate化

```cpp
    //  example/cpp03_syntax/class_06_ut.cpp 138

    class Person {
    public:
        static int instance_counter;

        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ
        ~Person(void);  // デストラクタ

        uint32_t    calc_bmi(void);                            // メンバ関数
        char const* get_full_name(void) { return full_name; }  // クラス内部でのメンバ関数定義

    private:  // メンバ変数への外部からのアクセスを禁止する
        static char* make_full_name(char const* family_name, char const* first_name);

        char const* family_name;
        char const* first_name;
        char*       full_name;  // 新規メンバ

        uint32_t height_cm;  // 身長 (cm単位と仮定)
        uint32_t weight_kg;  // 体重 (kg単位と仮定)
    };

    int Person::instance_counter = 0;  // これが無いとリンクエラーになる
                                       // ここでは0に初期化するが、デフォルト初期でも問題ない

    Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
        : family_name(family_name), first_name(first_name),
          full_name(make_full_name(family_name, first_name)),
          height_cm(height_cm), weight_kg(weight_kg)  
    {
        // コンストラクタの中身は省略
        // ...
        ++instance_counter;  // コンストラクタが呼ばれたため、インスタンスの数が一つ増えた
    }

    char* Person::make_full_name(char const* family_name, char const* first_name)
    {
        // 関数の中身は変わっていないので省略
        // ...
    }

    Person::~Person(void)  // デストラクタの定義。
    {
        if (full_name) {
            free((void*)full_name);
        }

        --instance_counter;  // デストラクタが呼ばれたのでインスタンスの数が一つ減った
    }
```

コードを修正した場合、それに合わせて単体テストも修正する必要がある。

```cpp
    //  example/cpp03_syntax/class_06_ut.cpp 229

    ASSERT_EQ(Person::instance_counter, 0);  // staticな変数はデフォルト初期化される

    Person taro("yamada", "taro", 173, 75);             // オブジェクトの生成
    ASSERT_STREQ(taro.get_full_name(), "yamada taro");  // 文字列として同値
    ASSERT_EQ(Person::instance_counter, 1);

    {
        Person jiro("yamada", "jiro", 170, 70);  // オブジェクトの生成
        {
            Person saburo("yamada", "saburo", 183, 80);  // オブジェクトの生成
            ASSERT_EQ(Person::instance_counter, 3);
        }  // この行でsaburoは解放される

        ASSERT_EQ(Person::instance_counter, 2);
    }  // この行でjiroは解放される

    ASSERT_EQ(Person::instance_counter, 1);  // jiro、saburoが解放された
```

### コピーコンストラクタ/コピー代入演算子 <a id="SS_2_1_8"></a>
コピーコンストラクタとは、

* 型Tに対して、`T(T const&)`のようなシグネチャのコンストラクタの一種である。
* オブジェクトのコピー初期化を制御するためのメンバ関数である。
* コピーコンストラクタをユーザが定義しない場合、自動的に暗黙定義される。

コピー代入演算子とは、

* 型Tに対して、`operator =(T const&)`のようなシグネチャの[特殊メンバ関数](core_lang_spec.md#SS_8_6_1)である。
* Tオブジェクトに別のTオブジェクトを代入するための[特殊メンバ関数](core_lang_spec.md#SS_8_6_1)である。
* コピー代入演算子をユーザが定義しない場合、自動的に暗黙定義される。

```cpp
    //  example/cpp03_syntax/c_syle_ut.cpp 7

    struct C_Struct {  // Cの構造体
        int         x;
        int         y;
        char const* str;
    };
```
```cpp
    //  example/cpp03_syntax/c_syle_ut.cpp 18

    struct C_Struct a = {
        1,
        2,
        "a",
    };

    struct C_Struct b = {
        3,
        4,
        "b",
    };

    b = a;  // bはaの値をコピーされる
    ASSERT_EQ(a.x, b.x);
    ASSERT_EQ(a.y, b.y);
    ASSERT_EQ(a.str, b.str);  // 通常の基本型と同様に、ポインタもコピーされる

    struct C_Struct c = a;  // cはaの値で初期化される
    ASSERT_EQ(a.x, c.x);
    ASSERT_EQ(a.y, c.y);
    ASSERT_EQ(a.str, c.str);  // 通常の基本型と同様に、ポインタもコピーされる

```

上記のコードは「Cの構造体インスタンスの`=`による代入は、
メンバの逐次コピーによって全体の代入や初期化が行われる」ことを示している。

C++では、この挙動がそのまま「暗黙定義されたコピーコンストラクタ/コピー代入演算子」
として取り込まれている。

すなわち、Cの構造体のコピーと同様に、C++のクラスでもユーザが特別に定義しなければ、
すべてのメンバが逐次コピーされる。

ただし、この方法ではポインタ型のメンバも単純にアドレスがコピーされるため、
リソースの二重解放や参照の共有によるバグの原因となる可能性がある。

以下は二重解放バグの典型的なコード例である([staticメンバ](cpp03_syntax.md#SS_2_1_7)の例からメンバ変数を除いている)。

```cpp
    //  example/cpp03_syntax/class_07_ut.cpp 15

    class Person {
    public:
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ
        ~Person(void);  // デストラクタ

        uint32_t    calc_bmi(void);                            // メンバ関数
        char const* get_full_name(void) { return full_name; }  // クラス内部でのメンバ関数定義

    private:  // メンバ変数への外部からのアクセスを禁止する
        static char* make_full_name(char const* family_name, char const* first_name);

        char const* family_name;
        char const* first_name;
        char*       full_name;  // 新規メンバ

        uint32_t height_cm;  // 身長 (cm単位と仮定)
        uint32_t weight_kg;  // 体重 (kg単位と仮定)
    };

    Person::Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg)
        : family_name(family_name), first_name(first_name),
          full_name(make_full_name(family_name, first_name)),
          height_cm(height_cm), weight_kg(weight_kg)
    {
        // コンストラクタの中身は省略
        // ...
    }

    char* Person::make_full_name(char const* family_name, char const* first_name)
    {
        // 関数の中身は変わっていないので省略
        // ...
    }

    Person::~Person(void)  // デストラクタの定義
    {
        if (full_name) {
            free((void*)full_name);
        }
    }
```
```cpp
    //  example/cpp03_syntax/class_07_ut.cpp 104

    {
        Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成

        ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
        Person person1 = person0;  // person0.full_nameがperson1.full_nameに単純コピー

        ASSERT_EQ(person0.calc_bmi(), person1.calc_bmi());
        ASSERT_STREQ(person0.get_full_name(), person1.get_full_name());
    }  // オブジェクトが解放される順序は、生成された順序の逆となる(person1 -> person0)
       // 1行上の行の実行でperson1.~Person()が呼び出され、free(person1.full_name)が実行され、
       // 2行上の行の実行でperson0.~Person()が呼び出され、free(person0.full_name)が実行される
       // このため、full_nameは二重解放される
```

三の原則(Rule of Three)に従うことで上記の問題を避けることができる
(C++11ではこの原則は[五の原則(Rule of Five)](cpp_idioms.md#SS_10_7_2)に拡張された)。

* オブジェクト生成時にリソースを確保するようなクラスは、ユーザが定義したデストラクタを持つ必要がある。
* ユーザが定義したデストラクタを持つクラスはコピーコンストラクタを持つ必要がある。
* ユーザが定義したコピーコンストラクタを持つクラスはコピー代入演算子を持つ必要がある。

以下にこの原則に従ったPersonを示す。

```cpp
    //  example/cpp03_syntax/class_08_ut.cpp 9

    class Person {
    public:
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);  // コンストラクタ

        Person(Person const& rhs);             // コピーコンストラクタの宣言
        Person& operator=(Person const& rhs);  // コピー代入演算子の宣言

        ~Person(void);                                               // デストラクタ
        uint32_t    calc_bmi(void);                                  // メンバ関数
        char const* get_full_name(void) const { return full_name; }  // クラス内部でのメンバ関数定義
    private:  // メンバ変数への外部からのアクセスを禁止する
        static char* make_full_name(char const* family_name, char const* first_name);
        char const*  family_name;
        char const*  first_name;
        char*        full_name;  // 新規メンバ
        uint32_t     height_cm;  // 身長 (cm単位と仮定)
        uint32_t     weight_kg;  // 体重 (kg単位と仮定)
    };
    // 以下省略
    // ...
```

以下にコピーコンストラクタの実装を示す。

```cpp
    //  example/cpp03_syntax/class_08_ut.cpp 79

    // コピーコンストラクタの実装
    Person::Person(Person const& rhs)
        : family_name(rhs.family_name),
          first_name(rhs.first_name),
          full_name(make_full_name(rhs.family_name, rhs.first_name)),
          height_cm(rhs.height_cm),
          weight_kg(rhs.weight_kg)
    {
    }
```

以下にコピー代入演算子の実装を示す。

```cpp
    //  example/cpp03_syntax/class_08_ut.cpp 91

    // コピー代入演算子の実装
    Person& Person::operator=(Person const& rhs)
    {
        // 自己代入チェック
        if (this == &rhs) {
            return *this;
        }
        family_name = rhs.family_name;
        first_name  = rhs.first_name;

        delete[] full_name;
        char* temp = new char[strlen(rhs.full_name) + 1];

        strcpy(temp, rhs.full_name);
        full_name = temp;
        height_cm = rhs.height_cm;
        weight_kg = rhs.weight_kg;
        return *this;
    }
```

以下にコピーコンストラクタ/コピー代入演算子のテストを示す。

```cpp
    //  example/cpp03_syntax/class_08_ut.cpp 130

    {
        Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成

        ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
        Person person1 = person0;                              // コピーコンストラクタ

        ASSERT_EQ(person0.calc_bmi(), person1.calc_bmi());

        //  full_nameが単純にコピーされただけならば、
        //  person0.get_full_name() == person1.get_full_name()が成立するはずである
        ASSERT_NE(person0.get_full_name(), person1.get_full_name());
        ASSERT_STREQ(person0.get_full_name(), person1.get_full_name());

        Person person2("asada", "jiro", 170, 70);

        ASSERT_EQ(24, person2.calc_bmi());
        ASSERT_STREQ(person2.get_full_name(), "asada jiro");

        person0 = person0;  // 自己代入は何もしない
        person0 = person2;

        ASSERT_EQ(person0.calc_bmi(), person2.calc_bmi());
        ASSERT_STREQ(person0.get_full_name(), person2.get_full_name());
    }  // この行で新規に確保したメモリは正確に解放される

```

一般に、T型のコピー代入演算子の戻り値型を`T&`にすることで以下のようなコードを実現できる。

```cpp
    //  example/cpp03_syntax/class_08_ut.cpp 159

    Person p0("yamada", "taro", 173, 75);
    Person p1("yamada", "jiro", 170, 70);
    Person p2("yamada", "saburo", 170, 70);

    ASSERT_STRNE(p0.get_full_name(), p1.get_full_name());  // p0、p1のフルネームが異なることの確認
    ASSERT_STRNE(p1.get_full_name(), p2.get_full_name());  // p1、p2のフルネームが異なることの確認

    p2 = p1 = p0;  // operator= の戻り値型がPerson&であるために可能になる
    ASSERT_STREQ(p0.get_full_name(), p1.get_full_name());  // p0、p1のフルネームが等しいことの確認
    ASSERT_STREQ(p1.get_full_name(), p2.get_full_name());  // p1、p2のフルネームが等しいことの確認

    // p2 = p1 = p0;  を通常の関数呼び出しとして展開すると下記のようになる
    p2.operator=(p1.operator=(p0));
```

なお、コピーコンストラクタ/コピー代入演算子を追加する前のコードが持っていた単純なコピーを[シャローコピー](cpp_idioms.md#SS_10_10_1)と呼び、
このコード例のようなコピーを[ディープコピー](cpp_idioms.md#SS_10_10_2)と呼ぶ。

上記コードには、C99には存在しない以下のようなシンタックスやキーワードを含む。

* [リファレンス](core_lang_spec.md#SS_8_8)(型Tに対して、`T&`という形式)
* [this](cpp03_syntax.md#SS_2_1_9)
* [new/delete](cpp03_syntax.md#SS_2_8)
* [constメンバ関数](cpp03_syntax.md#SS_2_1_10)(宣言の末尾にconstがついているメンバ関数)


### this <a id="SS_2_1_9"></a>
thisとは、メンバ関数内で暗黙的に利用可能なポインタであり、
そのメンバ関数を呼び出したオブジェクト自身を指す。thisポインタを用いることで、
メンバ変数やメンバ関数に明示的にアクセスでき、
特にパラメータ名とメンバ変数名が衝突する場合や、オブジェクト自身を返す必要がある場合に有用である。

thisのポインタとしての型は、そのメンバ関数が[constメンバ関数](cpp03_syntax.md#SS_2_1_10)か否かによって異なる。

| メンバ関数関数    | thisの型(Tはクラス型)  |
|:----------------- |:----------------------:|
| 非constメンバ関数 | T* const               |
| constメンバ関数   | const T* const         |

thisポインタ自体は常にconst（再代入不可）である。
下記例にあるように呼び出し関数がメンバであることを明示するために用いることがある。

```cpp
    //  example/cpp03_syntax/this_ut.cpp 8

    class A {
    public:
        A()
        {
            /* thisの型はA* constであるため、代入はコンパイルエラー
            this = 0; */
        }

        A* this_ptr() { return this; }

        void func0() {}
        void func1()
        {
            extern void func0();

            func0();        // メンバ関数func0の呼び出し
            ::func0();      // クラスAの外部の関数func0の呼び出し
            this->func0();  // クラスAの外部の関数func0の呼び出しではなく、メンバ関数func0の呼び出しであることの明記
        }
    };
```
```cpp
    //  example/cpp03_syntax/this_ut.cpp 34

    A a;

    A* a_ptr = &a;

    ASSERT_EQ(a_ptr, a.this_ptr());  // this_ptrはthisを返す。 thisがオブジェクトのポインタを指すことのテスト
```

以下のPersonのコピー代入演算子のようにthisを使用し自己代入を避けることが一般的である。

```cpp
    //  example/cpp03_syntax/class_08_ut.cpp 91

    // コピー代入演算子の実装
    Person& Person::operator=(Person const& rhs)
    {
        // 自己代入チェック
        if (this == &rhs) {
            return *this;
        }
        family_name = rhs.family_name;
        first_name  = rhs.first_name;

        delete[] full_name;
        char* temp = new char[strlen(rhs.full_name) + 1];

        strcpy(temp, rhs.full_name);
        full_name = temp;
        height_cm = rhs.height_cm;
        weight_kg = rhs.weight_kg;
        return *this;
    }
```

### constメンバ関数 <a id="SS_2_1_10"></a>
constメンバ関数は、オブジェクトの状態(非mutableメンバ変数)を変更しないことを宣言するメンバ関数である。
関数宣言の末尾にconst修飾子を付けて定義する。

- 意味論:  
    constメンバ関数内では、[this](cpp03_syntax.md#SS_2_1_9)ポインタが`const T*`型となり、
    非constメンバ変数への代入や非constメンバ関数の呼び出しができない。
- const正当性:  
    constオブジェクトからはconstメンバ関数のみ呼び出し可能である。
    これにより、const参照やconstポインタ経由でのアクセス時の安全性が保証される。
- 論理的const:  
    mutableキーワードを用いることで、
    論理的にはconstでも物理的には変更可能なメンバ(キャッシュ、カウンタなど)を実装できる。

```cpp
    //  example/cpp03_syntax/const_ut.cpp 6

    class Rectangle {
    public:
        Rectangle(int w, int h) : width_(w), height_(h), area_cache_(0), cache_valid_(false) {}
        //                                   ^^^ height_の値代入は初期化リストのみで行える

        int GetWidth() const { return width_; }    // constメンバ関数: オブジェクトの状態を変更しない
        int GetHeight() const { return height_; }  // constメンバ関数: オブジェクトの状態を変更しない

        // mutableメンバは変更可能
        int GetArea() const
        {
            if (!cache_valid_) {
                area_cache_  = width_ * height_;
                cache_valid_ = true;
            }
            return area_cache_;
        }

        // 非constメンバ関数であるため、オブジェクトの状態を変更できる
        void SetWidth(int w)
        {
            width_       = w;
            cache_valid_ = false;
        }

        void SetHeight(int h)
        {
            /* height_はconstであり変更できないため、コンパイルエラー
            height_      = h;
            */
            cache_valid_ = false;
        }

    private:
        int          width_;
        int const    height_;      // height_はオブジェクトの生成後、不変
        mutable int  area_cache_;  // mutableメンバ
        mutable bool cache_valid_;
    };
```
```cpp
    //  example/cpp03_syntax/const_ut.cpp 54

    Rectangle rect0(10, 30);
    rect0.SetWidth(3);
    ASSERT_EQ(90, rect0.GetArea());

    Rectangle const rect1(1, 3);
    /* rect1がconstであるため、下記コードはコンパイルエラー
    rect1.SetWidth(3);
    */
```

### constメンバ変数 <a id="SS_2_1_11"></a>
constメンバ変数は、オブジェクトの生存期間中、値が変更されないメンバ変数である。以下の特性を持つ。

- 初期化の必須性:  
    constメンバ変数は宣言時またはコンストラクタの初期化リストで必ず初期化しなければならない。
    コンストラクタ本体での代入は許されない。
- イミュータブル性:  
    一度初期化されると、オブジェクトの生存期間中、その値を変更することはできない。
- 設計上の利点:  
    変更不可能な属性を表現するのに適している。


コード例については、[constメンバ関数](cpp03_syntax.md#SS_2_1_10)を参照せよ。


### フレンド宣言 <a id="SS_2_1_12"></a>
フレンド宣言とは、あるクラスのprivateおよびprotectedメンバーへのアクセス権を、
特定の関数またはクラスに対して付与する宣言である。通常、クラスの非公開メンバーは外部からアクセスできないが、
フレンド宣言を用いることで、信頼できる特定の対象に限定してアクセスを許可できる。

```cpp
    //  example/cpp03_syntax/friend_ut.cpp 13

    class A {
    private:
        int data;

        friend class Friend_A1;  // クラスのフレンド宣言
        friend Friend_A2;        // C++11以降はclassキーワードを省略可能

        friend void func(A& obj)  // 関数のフレンド宣言
                                  // フレンド関数はクラス内部でも外部でも定義可能
        {
            obj.data = 0;  // フレンド宣言の効果でAのprivateにアクセスできる
        }
    };
```

__[特徴と注意点]__

* 非対称性  
  フレンド関係は一方向である。クラスAがクラスBをフレンドとして宣言しても、
  BがAのメンバーにアクセスできるだけで、AがBのメンバーにアクセスできるわけではない。
* 非推移性  
  フレンド関係は推移しない。AがBをフレンドとし、BがCをフレンドとしても、CはAのメンバーにアクセスできない。
* [継承]されない  
  フレンド関係は継承されない。基底クラスのフレンドは、派生クラスの非公開メンバーにアクセスできない。
* アクセス指定子との独立性  
  フレンド宣言は、クラス定義内のどのアクセス指定子セクション(private、protected、public)に記述しても同じ効果を持つ。

### 等値比較演算子 <a id="SS_2_1_13"></a>
等値比較演算子(operator==)とは、2つのオブジェクトが等しいかどうかを判定するための演算子である。
C++では、クラスに対してこの演算子をオーバーロードすることで、そのクラス特有の等値性の定義を実装できる。
等値比較演算子は通常、メンバ関数ではなくフレンド関数または非メンバ関数として実装することが推奨される。
これは、左辺と右辺のオペランドを対称的に扱えるようにするためである。
メンバ関数として実装した場合、左辺が必ずそのクラスのオブジェクトでなければならないという制約が生じる。
演算子の戻り値はbool型であり、2つのオブジェクトが等しい場合にtrueを、そうでない場合にfalseを返す。
等値比較の実装においては、すべての意味のあるメンバ変数を比較対象に含める必要がある。
ただし、キャッシュやミュータブルな一時データなど、
オブジェクトの論理的な等価性に影響しないメンバは、通常、比較対象から除外する。
等値比較演算子を実装する際には、不等比較演算子(operator!=)も合わせて実装するのが一般的である。
C++20以降では、operator==のみを実装すればoperator!=は自動的に導出されるが、
それ以前のC++では両方を明示的に実装する必要がある。
また、等値比較演算子はや[コピーコンストラクタ/コピー代入演算子](cpp03_syntax.md#SS_2_1_8)は、
[等価性のセマンティクス](cpp_idioms.md#SS_10_5_1)を満たす必要がある。

コード例は、次節で示す。


### Personのリファクタリング <a id="SS_2_1_14"></a>
これまで例示してきたPersonを以下の方針でリファクタリングを行う。

* 可読性向上のために、[Trailing Underscore(末尾アンダースコア)](cpp_idioms.md#SS_10_9_4)に従う。
* メンバを適切にconst修飾することで、[constメンバ関数](cpp03_syntax.md#SS_2_1_10)/[constメンバ変数](cpp03_syntax.md#SS_2_1_11)へ変更する。
* Cでは、引数を持たない関数funcは`func(void)`のように宣言するが、C++では通常、単に`func()`と書く。
* 単体テストの利便性のためにPersonに[フレンド宣言](cpp03_syntax.md#SS_2_1_12)した[等値比較演算子](cpp03_syntax.md#SS_2_1_13)を追加する
  (セオリーではリファクタリングで機能変更するべきではないが、ドキュメントの構成上の都合でこうする)。

```cpp
    //  example/cpp03_syntax/class_09_ut.cpp 10

    class Person {
    public:
        Person(char const* family_name, char const* first_name, uint32_t height_cm, uint32_t weight_kg);
        Person(Person const& rhs);
        Person& operator=(Person const& rhs);
        ~Person();

        uint32_t    calc_bmi() const;
        char const* get_full_name() const { return full_name_; }

    private:
        static char* make_full_name(char const* family_name, char const* first_name);

        char const* family_name_;  // Trailing Underscoreを使用
        char const* first_name_;
        char const* full_name_;

        uint32_t height_cm_;
        uint32_t weight_kg_;

        friend bool operator==(Person const& lhs, Person const& rhs);  // 等値比較演算子のフレンド宣言
                                                                       // operator!=はフレンド宣言は不要
    };

    bool operator==(Person const& lhs, Person const& rhs)  // 等値比較演算子の定義
    {
        return std::strcmp(lhs.family_name_, rhs.family_name_) == 0 && std::strcmp(lhs.first_name_, rhs.first_name_) == 0
               && lhs.height_cm_ == rhs.height_cm_ && lhs.weight_kg_ == rhs.weight_kg_;
    }

    bool operator!=(Person const& lhs, Person const& rhs) { return !(lhs == rhs); }

    // 他の関数の実装は省略
    // ...
```
```cpp
    //  example/cpp03_syntax/class_09_ut.cpp 123

    Person person0("yamada", "taro", 173, 75);  // オブジェクトの生成
    Person person1("sato", "jiro", 173, 70);    // オブジェクトの生成

    ASSERT_STREQ(person0.get_full_name(), "yamada taro");  // 文字列として同値
    ASSERT_STREQ(person1.get_full_name(), "sato jiro");    // 文字列として同値
    ASSERT_EQ(25, person0.calc_bmi());

    ASSERT_TRUE(person0 == person0);  // 等値比較演算子のテスト(同一オブジェクトでのテスト)
    ASSERT_TRUE(person0 != person1);  // 等値比較演算子のテスト(!= テストも兼ねる)
    // 通常、上記2テストは以下のように書く
    ASSERT_EQ(person0, person0);
    ASSERT_NE(person0, person1);

    person0 = person1;            // コピー代入
    ASSERT_EQ(person0, person1);  // 等値比較演算子とコピー代入演算子のテスト
```

リファクタリングにより、以下の改善が実現された。

* メンバ変数名の末尾アンダースコアにより、引数名との区別が明確になった。
* メンバが適切にconst修飾されたことで可読性が向上した。
* malloc/freeからnew/deleteへ統一され、C++らしいメモリ管理となった。

### 演算子オーバーロード <a id="SS_2_1_15"></a>
工事中


## オーバーロード <a id="SS_2_2"></a>
オーバーロードとは、同じ名前の関数を引数の型や個数を変えて複数定義できる機能である。
C言語では関数名の重複は許されず、異なる型を扱う類似の関数には異なる名前を付ける必要がある。  

例えば標準ライブラリには`abs()`、`labs()`、`fabs()`のように、
整数、long、浮動小数点数それぞれに対応する絶対値関数が存在する。

C++では同じ操作に対して同じ関数名を使用でき、コンパイラが引数の型から適切な関数を選択する。

### オーバーロードの使用例 <a id="SS_2_2_1"></a>
オーバーロードの使用例を以下に示す。

```cpp
    //  example/cpp03_syntax/overload_ut.cpp 6

    int    max(int a, int b) { return (a > b) ? a : b; }        // max #1
    double max(double a, double b) { return (a > b) ? a : b; }  // max #2
    long   max(long a, long b) { return (a > b) ? a : b; }      // max #3
```
```cpp
    //  example/cpp03_syntax/overload_ut.cpp 15

    ASSERT_EQ(20, max(10, 20));        // max #1が呼ばれる
    ASSERT_EQ(3.14, max(3.14, 2.71));  // max #2が呼ばれる
    ASSERT_EQ(200, max(100L, 200L));   // max #3が呼ばれる
```

### オーバーロード解決の規則 <a id="SS_2_2_2"></a>
コンパイラは関数のシグネチャ(関数名、引数の型、引数の個数)に基づいて、どの関数を呼び出すかを決定する。
重要な点として、戻り値の型はオーバーロード解決に使用されない。

```cpp
    // これはエラー：戻り値の型だけが異なる
    int getValue();
    double getValue();  // コンパイルエラー
```

引数の個数が異なる場合もオーバーロード可能である。

```cpp
    //  example/cpp03_syntax/overload_ut.cpp 23

    int add(int a, int b) { return a + b; }                        // add #1
    int add(int a, int b, int c) { return a + b + c; }             // add #1
    int add(int a, int b, int c, int d) { return a + b + c + d; }  // add #1
```
```cpp
    //  example/cpp03_syntax/overload_ut.cpp 32

    ASSERT_EQ(2, add(1, 1));        // add #1が呼ばれる
    ASSERT_EQ(3, add(1, 1, 1));     // add #2が呼ばれる
    ASSERT_EQ(4, add(1, 1, 1, 1));  // add #2が呼ばれる
```

### オーバーロードと型変換/曖昧性 <a id="SS_2_2_3"></a>
関数呼び出し時、完全に一致する関数が存在しない場合、コンパイラは型変換を考慮する。
ただし、複数の候補が同等に適合する場合、曖昧性エラーとなる。

```cpp
    //  example/cpp03_syntax/overload_ut.cpp 40

    int abs(int a) { return (a < 0) ? -a : a; }    // abs #1
    int abs(float a) { return (a < 0) ? -a : a; }  // abs #2
```
```cpp
    //  example/cpp03_syntax/overload_ut.cpp 48

    abs(-1);     // abs #1が呼ばれる
    abs(-3.0f);  // abs #2が呼ばれる

    /* 3.0はdoubleであるため、
    abs(-3.0);   //abs #1を呼ぶべきか、abs #2を呼ぶべきかは曖昧である
    */
```

## デフォルト引数 <a id="SS_2_3"></a>
工事中

## テンプレート <a id="SS_2_4"></a>
### クラステンプレート <a id="SS_2_4_1"></a>
工事中

### 関数テンプレート <a id="SS_2_4_2"></a>
工事中

## 名前空間 <a id="SS_2_5"></a>
工事中

## 標準ライブラリ <a id="SS_2_6"></a>
標準ライブラリとは、C++言語仕様の一部として規定されている、再利用可能なクラスや関数の集合である。
文字列処理、コンテナ、アルゴリズム、入出力、数値演算など、プログラム開発に必要な基本的な機能を提供する。
標準ライブラリを使用することで、車輪の再発明を避け、移植性の高いコードを記述できる。
すべての実装はstd名前空間に属しており、標準ヘッダファイルをインクルードすることで利用可能になる。
構成要素は膨大であるため、良く使用されるものの一部を以下に示す
([cpprefjp.github.io](https://cpprefjp.github.io/reference.html))。

| 標準ライブラリ| クラス等                                               |
|:--------------|:------------------------------------------------------ |
| 文字列処理    | std::string、std::wstringなど                          |
| コンテナ      | std::vector、std::list、std::mapなど                   |
| アルゴリズム  | std::sort、std::find、std::copyなど                    |
| 入出力        | std::cout、std::cin、ファイル入出力など                |
| 反復子        | コンテナの要素にアクセスするための統一インターフェース |

### std::stringの使用例  <a id="SS_2_6_1"></a>
std::stringはC++標準ライブラリが提供する文字列クラスである。C言語の文字配列(char[])と比較して、
メモリ管理が自動化されており、文字列操作が安全かつ容易になる。

Cでの文字列の結合と比較は下記のように記述される。

```cpp
    //  example/cpp03_syntax/std_lib_ut.cpp 14

    char const* hello = "Hello";
    char const* world = "World";

    size_t hello_len = strlen(hello);
    size_t world_len = strlen(world);

    // Cでの文字列の結合
    char* hello_world = (char*)malloc(hello_len + 1 + world_len + 1);  // 間に1スペース入れる
    strcpy(hello_world, hello);
    hello_world[hello_len] = ' ';
    strcpy(hello_world + hello_len + 1, world);

    ASSERT_TRUE(strcmp(hello_world, "Hello World") == 0);  // 文字列の比較
    ASSERT_STREQ(hello_world, "Hello World");              // googletestでは上記はこの行と等価

    free(hello_world);  // これを忘れるとメモリリーク
```

C++では複雑な処理が、std::stringに押し込まれているため文字列の結合と比較は下記のように単純に記述できる。

```cpp
    //  example/cpp03_syntax/std_lib_ut.cpp 38

    char const* hello = "Hello";
    char const* world = "World";

    // C++での文字列の結合
    std::string str1 = hello;              // str1の初期化
    std::string str2 = world;              // str2の初期化
    std::string str3 = str1 + " " + str2;  // 文字列の連結
    std::string exp  = "Hello World";

    ASSERT_TRUE(exp == str3);  // std::stringは等値比較演算子が定義されているため、文字列の比較にstrcmpは不要
    ASSERT_EQ(exp, str3);  // googletestでは上記はこの行と等価
```

### 入出力(stream) <a id="SS_2_6_2"></a>
入出力(stream)とは、データの読み書きを抽象化した機能であり、C++標準ライブラリではiostreamライブラリとして提供される。
ストリームは、キーボード入力、画面出力、ファイル入出力など、
異なる入出力先を統一的なインターフェースで扱うことを可能にする。
C言語のprintf/scanfと比較して、型安全性が高く、ユーザー定義型に対する入出力の拡張が容易である。

```cpp
    //  example/cpp03_syntax/std_lib_ut.cpp 58

    int  age = 30;
    char name[100];

    // Cでの出力
    printf("Age: %d\n", age);  // 型指定子(%d)を誤ると実行時エラー

    // Cでの入力
    scanf("%s", name);  // バッファオーバーフローのリスクあり
```

以下のストリームオブジェクトが定義されている。

| ストリームオブジェクト | 機能                 |
|:----------------------:|:-------------------- |
| std::cin               | 標準入力を扱う       |
| std::cout              | 標準出力を扱う       |
| std::cerr              | 標準エラー出力を扱う |

ストリームオブジェクトは以下のように使用する。

```cpp
    //  example/cpp03_syntax/std_lib_ut.cpp 75

    int  age = 30;
    char name[100];

    // C++での出力
    std::cout << "Age: " << age << std::endl;  // 型は自動判別される

    // C++での入力
    std::cin >> name;  // std::stringは自動的にメモリを管理
```


ファイル入出力にはstd::ifstream(入力)、std::ofstream(出力)、std::fstream(入出力)を使用する。

```cpp
    //  example/cpp03_syntax/std_lib_ut.cpp 86

    // ファイル出力の例
    std::ofstream ofs("output.txt");

    if (ofs) {
        ofs << "Name: " << name << ", Age: " << age << std::endl;
    }
```

標準入出力やファイル入出力と同様に使用できるストリング入出力の使用例を以下に示す。

```cpp
    //  example/cpp03_syntax/std_lib_ut.cpp 100

    int               age = 30;
    std::string       name("Yamada Taro");
    std::stringstream oss;  // 出力string

    // stringstreamへの出力
    oss << name << '(' << "Age:" << age << ')';  // 型は自動判別される

    std::string exp("Yamada Taro(Age:30)");

    ASSERT_EQ(exp, oss.str());  // oss.str()はossが出力された文字列を返す
```

### コンテナ <a id="SS_2_6_3"></a>
工事中
標準ライブラリのコンテナとは...


## 継承 <a id="SS_2_7"></a>
継承は既存のクラスを拡張して新しいクラスを定義する機構である。既存のクラスを基底クラス(base class)、
新しく定義するクラスを派生クラス(derived class)と呼ぶ。
派生クラスは基底クラスのメンバ変数とメンバ関数を引き継ぐため、コードの再利用性が高まる。

以下の3種類の継承が規定されている。

- [public継承](cpp03_syntax.md#SS_2_7_1)
- [protectd継承](cpp03_syntax.md#SS_2_7_2)
- [private継承](cpp03_syntax.md#SS_2_7_3)

### public継承 <a id="SS_2_7_1"></a>
public継承は最も一般的な継承方法であり、主に「[is-a](cpp_idioms.md#SS_10_3_1)」関係を表現する際に使用される。
基底クラスのpublicメンバは派生クラスでもpublic、protectedメンバはprotectedのまま継承される。

```cpp
    //  example/cpp03_syntax/derived_ut.cpp 7

    class Base {
    public:
        int public_value_;

    protected:
        int protected_value_;

    private:
        int private_value_;
    };

    class Derived : public Base {
    public:
        void access()
        {
            public_value_    = 10;  // OK: publicメンバにアクセス可能
            protected_value_ = 20;  // OK: protectedメンバにアクセス可能
            /*
            private_value_ = 30;      NG: privateメンバにはアクセス不可 */
        }
    };
```
```cpp
    //  example/cpp03_syntax/derived_ut.cpp 34

    Derived d;
    d.public_value_ = 100;  // OK: 外部からpublicメンバにアクセス可能
    /*
    d.protected_value_ = 200;  NG: 外部からprotectedメンバにはアクセス不可 */
```

public継承では、
以下のコードのように派生クラスのオブジェクトを基底クラスのポインタや[リファレンス](core_lang_spec.md#SS_8_8)として扱うことができる。
これによりポリモーフィズムが実現される。

```cpp
    //  example/cpp03_syntax/derived_ut.cpp 42

    Base* b_ptr = &d;  // DerivedはBaseの一種であるめ、これが認められる
    Base& b_ref = d;   // DerivedはBaseの一種であるめ、これも認められる
```

### protectd継承 <a id="SS_2_7_2"></a>
protected継承は、基底クラスのpublicメンバとprotectedメンバがすべて派生クラスでprotectedになる。
外部からは基底クラスのメンバにアクセスできなくなる。

```cpp
    //  example/cpp03_syntax/derived_ut.cpp 53
    class Base {
    public:
        int public_value_;

    protected:
        int protected_value_;
    };

    class Derived : protected Base {
    public:
        void access()
        {
            public_value_    = 10;  // OK: protectedメンバとしてアクセス可能
            protected_value_ = 20;  // OK: protectedメンバとしてアクセス可能
        }
    };
```
```cpp
    //  example/cpp03_syntax/derived_ut.cpp 73

    Derived d;
    /*
    d.public_value_ = 100;    外部からはアクセス不可 */

    /*
    Base* b_ptr = &d;  public継承とは異なり、これは認められない
    Base& b_ref = d;   public継承とは異なり、これも認められない */
```

protected継承は実装の詳細を隠蔽しつつ、
さらに派生したクラスには基底クラスのインターフェースを公開したい場合に使用される。使用頻度は低い。

### private継承 <a id="SS_2_7_3"></a>
private継承は、基底クラスのpublicメンバとprotectedメンバがすべて派生クラスでprivateになる。
派生クラス内部でのみ基底クラスのメンバにアクセスでき、外部からも、さらに派生したクラスからもアクセスできない。

```cpp
    //  example/cpp03_syntax/derived_ut.cpp 89

    class Base {
    public:
        int  public_value_;
        void show() { printf("Base::show()\n"); }

    protected:
        int protected_value_;
    };

    class Derived : private Base {
    public:
        void access()
        {
            public_value_    = 10;  // OK: privateメンバとしてアクセス可能
            protected_value_ = 20;  // OK: privateメンバとしてアクセス可能
            show();                 // OK: privateメンバとしてアクセス可能
        }
    };

    class MoreDerived : public Derived {
    public:
        void access()
        {
            // public_value_ = 30;   // NG: Baseのメンバにはアクセス不可
        }
    };

```
```cpp
    //  example/cpp03_syntax/derived_ut.cpp 121
    Derived d;

    /*
    d.public_value_ = 100;      外部からはアクセス不可
    d.show();                   外部からはアクセス不可  */

    /*
    Base* b_ptr = &d;  public継承とは異なり、これは認められない
    Base& b_ref = d;   public継承とは異なり、これも認められない */
```

private継承は「[has-a](cpp_idioms.md#SS_10_3_2)関係」や「[is-implemented-in-terms-of](cpp_idioms.md#SS_10_3_3)関係」を表現する際に使用されることがある。
ただし、一般的にはメンバ変数として保持する方が意図が明確になるため、private継承の使用頻度は非常に低い。

### 派生 <a id="SS_2_7_4"></a>
派生とは、継承を使って既存のクラスから新しいクラスを作り出すことである。この過程で、基底クラスの機能を受け継ぎつつ、
派生クラス独自の機能を追加したり、既存の機能を変更したりできる。

**派生の主な目的**は以下の通りである。

- 機能の拡張:  
  基底クラスの機能をそのまま利用しつつ、新しいメンバ変数やメンバ関数を追加することで、
  より特化した機能を持つクラスを定義できる。
- 機能の特殊化:  
  基底クラスの一般的な振る舞いを、派生クラスで特定の用途に合わせて変更できる。仮想関数のオーバライドにより、
  同じインターフェースで異なる実装を提供することが可能になる。
- コードの再利用:  
    共通する機能を基底クラスにまとめることで、重複したコードを避けられる。
    複数の派生クラスが同じ基底クラスを継承することで、保守性が向上する。

派生は多段階に行うことができる。派生クラスをさらに基底クラスとして、別の派生クラスを定義することが可能である。
これにより、クラスの階層構造を形成できる。階層が深くなると、
下位の派生クラスは上位のすべての基底クラスのメンバを継承する。ただし、階層を深くしすぎると設計が複雑になり、
保守性が低下する可能性があるため、適切な深さに抑えることが重要である。

派生クラスを設計する際は、「[is-a](cpp_idioms.md#SS_10_3_1)」関係が成立するかを確認する必要がある。
派生クラスは基底クラスの一種であるという関係が自然に成り立つ場合に、public継承を使用するべきである。
また、派生クラスは基底クラスのインターフェースを尊重し、[リスコフの置換原則(LSP)](temp.md#SS_4_4)に従うことが望ましい。
これは、基底クラスのポインタや参照を通じて派生クラスのオブジェクトを操作しても、
プログラムの正しさが保たれるという原則である。

### オーバーライド <a id="SS_2_7_5"></a>
工事中

--- 

## new/delete <a id="SS_2_8"></a>
Cの`malloc`/`free`と異なり、
C++ではメモリアロケーションとオブジェクトの生成と破棄を適切に行うために、以下の演算子が定義されている。

* [new演算子](cpp03_syntax.md#SS_2_8_1)/[delete演算子](cpp03_syntax.md#SS_2_8_2)
* [new[]演算子](cpp03_syntax.md#SS_2_8_3)/[delete[]演算子](cpp03_syntax.md#SS_2_8_4)

上記のnew演算子以外に[プレースメントnew](core_lang_spec.md#SS_8_6_9)と[new (std::nothrow)](core_lang_spec.md#SS_8_6_10)が定義されているが、
これらの対となるdeleteは存在しない。


### new演算子 <a id="SS_2_8_1"></a>
### delete演算子 <a id="SS_2_8_2"></a>
`new`演算子は、ヒープ上にメモリを確保し、オブジェクトを構築する。  
`delete`演算子は、`new`で確保したメモリを解放する前に、デストラクタを呼び出す。

```cpp
    //  example/cpp03_syntax/new_delete_ut.cpp 96

    int*    p      = new int;                                // int型のメモリを確保(未初期化)
    int*    q      = new int(42);                            // int型のメモリを確保し、42で初期化
    Person* person = new Person("yamada", "taro", 173, 75);  // コンストラクタを呼び出す

    ASSERT_EQ(*q, 42);
    ASSERT_STREQ(person->get_full_name(), "yamada taro");

    delete p;       // pが指すメモリを解放
    delete q;       // qが指すメモリを解放
    delete person;  // personのデストラクタを呼び出してからメモリを解放
```

### new[]演算子 <a id="SS_2_8_3"></a>
### delete[]演算子 <a id="SS_2_8_4"></a>
配列を動的に確保する場合は、new[]とdelete[]を使用する。


```cpp
    //  example/cpp03_syntax/new_delete_ut.cpp 113

    // 配列の生成
    int*    array   = new int[10];    // 10個のint型配列を確保
    Person* persons = new Person[5];  // 5個のPersonオブジェクトの配列を確保

    // 配列の解放
    delete[] array;    // 配列全体を解放
    delete[] persons;  // 各要素のデストラクタを呼び出してから配列を解放
```

[注]

* クラスTに対し`new T[N]`を実行するためにはTがデフォルトコンストラクタを持つ必要がある。
* new[]でアロケートしたメモリはdelete[]で解放しなければならない。







