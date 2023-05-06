// 双重检测单例模式
public static A getInstance(){
  if (instance == null) {
      synchronized (A.class) {
          if (instance == null) {
              instance = new A();
          }
      }
  }
  return instance;
}
