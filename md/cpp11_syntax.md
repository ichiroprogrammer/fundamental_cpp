# C++11 シンタックス解説ドキュメント

このドキュメントは、`programming_convention.md`、`cpp_improve.md`、`term_explanation.md` の内容を理解するために、
特に **C++11** で導入された新しいシンタックスや機能を解説する。

---

## 1. 型推論と関連機能

### auto
C++11 では `auto` により、変数宣言時に右辺値から型を推論できる【44†cpp_improve.md】。

```cpp
auto i = 1;       // int
auto d = 1.5;     // double
auto s = "str";   // const char*
```

### decltype
式の型を取得するキーワード【44†cpp_improve.md】。

```cpp
int a = 0;
decltype(a) b = 1;   // b は int
```

### nullptr
従来の `NULL` の代わりに導入されたヌルポインタリテラル。型安全性が向上【44†cpp_improve.md】。

```cpp
int* p = nullptr;  // OK
// int i = nullptr;  // コンパイルエラー
```

---

## 2. 構文の追加

### 範囲for文
配列やコンテナの要素を直接扱える for 構文【44†cpp_improve.md】。

```cpp
std::vector<int> v = {1,2,3};
for (auto x : v) {
    std::cout << x << std::endl;
}
```

### 一様初期化
`{}` による統一的な初期化構文【44†cpp_improve.md】。

```cpp
int x{1};
std::vector<int> v{1,2,3};
```

---

## 3. クラス関連の拡張

### default/delete
特殊メンバ関数を明示的に自動生成または削除できる【44†cpp_improve.md】。

```cpp
struct X {
    X() = default;            // デフォルトコンストラクタ生成
    X(const X&) = delete;     // コピーは禁止
};
```

### 委譲コンストラクタ
あるコンストラクタから他のコンストラクタを呼べる【44†cpp_improve.md】。

```cpp
struct A {
    int x;
    A(int n) : x(n) {}
    A() : A(0) {}  // 委譲
};
```

### 継承コンストラクタ
基底クラスのコンストラクタを継承できる【44†cpp_improve.md】。

```cpp
struct B { B(int) {} };
struct D : B {
    using B::B;  // 継承コンストラクタ
};
```

### override/final
仮想関数のオーバーライドを明示でき、final により継承やオーバーライドを禁止できる【44†cpp_improve.md】。

```cpp
struct Base { virtual void f(); };
struct Derived : Base {
    void f() override;   // オーバーライドを明示
    void g() final;      // g は派生クラスでオーバーライド禁止
};
```

---

## 4. テンプレート関連

### エイリアステンプレート
型エイリアスにテンプレートを使える【44†cpp_improve.md】。

```cpp
template<typename T>
using Vec = std::vector<T>;
Vec<int> vi;  // std::vector<int> と同じ
```

### パラメータパック
可変個のテンプレート引数を受け取れる【45†template_meta_programming.md】。

```cpp
template <typename... Args>
void f(Args... args) {
    std::cout << sizeof...(args) << std::endl;
}
```

### extern template
テンプレートのインスタンス化を制御できる【44†cpp_improve.md】。

```cpp
extern template class std::vector<int>;  // ここでは生成しない
```

---

## 5. 式とセマンティクス

### move セマンティクス / rvalue 参照
資源のムーブを可能にする仕組み【44†cpp_improve.md】【46†term_explanation.md】。

```cpp
std::vector<int> f() {
    std::vector<int> v{1,2,3};
    return v;   // ムーブ
}
```

### noexcept
例外を投げないことを明示する【44†cpp_improve.md】。

```cpp
void g() noexcept { }
```

### constexpr
コンパイル時に評価できる定数式や関数【44†cpp_improve.md】【46†term_explanation.md】。

```cpp
constexpr int square(int x) { return x*x; }
int arr[square(3)];  // OK
```

### ユーザー定義リテラル
接尾辞をつけてリテラルを拡張できる【44†cpp_improve.md】。

```cpp
constexpr long double operator"" _deg(long double d) {
    return d * 3.14159265358979323846 / 180.0;
}
auto rad = 90.0_deg;
```

---

## 6. enumの拡張

### enum class (スコープドenum)
型安全な列挙を導入【46†term_explanation.md】。

```cpp
enum class Color { Red, Green, Blue };
Color c = Color::Red;
```

### underlying type
enum の基底型を指定できる【46†term_explanation.md】。

```cpp
enum class E : uint8_t { A, B, C };
```

---

## 7. 標準ライブラリ関連

### std::array
固定長配列クラス【44†cpp_improve.md】。

```cpp
std::array<int, 3> a{{1,2,3}};
```

### std::unordered_map / std::unordered_set
ハッシュベースの連想コンテナ【44†cpp_improve.md】。

```cpp
std::unordered_map<std::string, int> m{{"a",1},{"b",2}};
```

### std::forward_list
単方向リンクリスト【44†cpp_improve.md】。

---

## まとめ

C++11 は、型推論・ラムダ式・rvalue参照とムーブセマンティクス・一様初期化・enum class など、
**表現力と安全性を大幅に強化した言語仕様**を導入した。
これらのシンタックスを理解することで、`programming_convention.md` や `cpp_improve.md`、`term_explanation.md` の内容を
スムーズに読み進められる。