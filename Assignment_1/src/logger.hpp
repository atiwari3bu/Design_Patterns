class Singleton_Logger{

    static Singleton_Logger* _Instance;
    static int _DEBUG_LEVEL;

    Singleton_Logger(){} // Constructor made private
    Singleton_Logger(int temp){} // Constructor made private

    public:
    Singleton_Logger* getInstance(int DEBUG_LEVEL){ 
        if(!_Instance){
            this->_DEBUG_LEVEL=DEBUG_LEVEL;
            _Instance = new Singleton_Logger(DEBUG_LEVEL);
        }

        return _Instance;
    }

};
