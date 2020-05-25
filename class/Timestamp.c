class Timestamp
{
    private static const int m_DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /**
     * Based on: https://en.wikipedia.org/wiki/Unix_time
     * Same code but in JS: https://codepen.io/djctavia-real/pen/GRpLxgm
     * 
     * @param {int} year
     * @param {int} month
     * @param {int} day
     * @param {int} hour
     * @param {int} minute
     * @param {int} second
     * 
     * @return Timestamp in MS
     */
    static int Calcul(int year, int month, int day, int hour, int minute, int second)
    {
        bool isLeapYear = IsLeapYear();
        int timestamp = 0;

        for (int iYear = 1970; iYear < year; ++iYear)
        {
            if (iYear % 4)
                timestamp += 86400 * 365;
            else
                timestamp += 86400 * 366;
        }
        for (int iMonth = 0; iMonth < month; iMonth++)
        {
            if (isLeapYear && iMonth == 1)
                timestamp += 86400;
            timestamp += m_DaysInMonth[iMonth] * 86400;
        }
        for (int iDay = 1; iDay < day; iDay++)
        {
            timestamp += 86400;
        }
        timestamp += hour * 3600;
        timestamp += minute * 60;
        timestamp += second;
        return timestamp * 1000;
    }

    static bool IsLeapYear(int year)
    {
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        if (year % 4 == 0)
            return true;
        return false;
    }
};