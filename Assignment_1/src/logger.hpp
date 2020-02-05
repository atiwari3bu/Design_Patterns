class Singleton_Logger{

    static Singleton_Logger* _Instance;
    static int _DEBUG_LEVEL;

    public:
    Singleton_Logger(int DEBUG_LEVEL){ 
        if(!_Instance){
            this->_DEBUG_LEVEL=DEBUG_LEVEL;
            _Instance = new Singleton_Logger(DEBUG_LEVEL);
        }

        return _Instance;
    }

};
