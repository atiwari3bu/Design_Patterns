class Singleton_Logger{

    static Singleton_Logger* _Instance; 
    int _DEBUG_LEVEL;

    Singleton_Logger(){} // Constructor made private
    Singleton_Logger(int DEBUG_LEVEL){ // Constructor made private
        _DEBUG_LEVEL=DEBUG_LEVEL;
    }

    public:
    static Singleton_Logger* getInstance(int DEBUG_LEVEL);
};



Singleton_Logger* Singleton_Logger::getInstance(int DEBUG_LEVEL){ 

    if(!_Instance){
        _Instance = new Singleton_Logger(DEBUG_LEVEL);
    }

    return _Instance;

}
