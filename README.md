# DataMaker

![Screenshot from 2020-10-04 23-44-17](https://user-images.githubusercontent.com/57752033/95018570-99810880-069b-11eb-98c5-57f61c9e7a13.png)

クラスタリングアルゴリズムのテスト用のデータセットの作成を手助けする、Gtkmmベースのアプリケーションです。<br>
ビルドには事前に`gtkmm`の環境構築が必要です。

___

This program supports to make your original datasets for testing clustering algorithm. <br>
This program needs to use `gtkmm` for building. Please install it for your device before.<br>

### ビルド例 command

```
g++ -o data_maker data_maker.cpp `pkg-config --libs --cflags gtkmm-3.0`
```

### 使い方

マウスでウインドウの適当な位置をクリックすることで、そこに新しいデータが生成されます。
保存するときは`s`キーを押してください。



