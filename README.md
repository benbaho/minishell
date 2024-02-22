# minishell


Bu proje, Bash programının bir taklidi olarak yazılmıştır. Proje, C dili kullanılarak Ecole 42'de geliştirilmiştir. Projenin amacı, Bash programlarının temel fonksiyonlarını taklit etmek ve execve fonksiyonunu kullanarak diğer programları çalıştırmaktır.

Proje, aşağıdaki Bash komutlarının taklitlerini içermektedir

cd: Dizin değiştirmek için kullanılır.

echo: Konsola bir metin yazdırmak için kullanılır.

pwd: Geçerli dizinin yolunu yazdırmak için kullanılır.

export: Sistem değişkenlerini oluşturmak veya değiştirmek için kullanılır.

unset: Sistem değişkenlerini silmek için kullanılır.

env: Sistem değişkenlerini listelemek için kullanılır.

Ayrıca projede, aşağıdaki fonksiyonları kullanmaktadır

pipe: Bir komutun çıktısını başka bir komutun girdisi olarak kullanmayı sağlar.

dup: Bir dosya tanıtıcısının çiftine yönlendirme yapar.

dup2: Bir dosya tanıtıcısının çiftine yönlendirme yapar ve eski çifti kapatır.

readline: Kullanıcıdan satır bazlı girdi almak için kullanılır.

execve: Bir programı çalıştırmak için kullanılır.

heredoc: Komut satırından okunan veriyi belirli bir formatta yazdırmak için kullanılır.
