import sys

START = 0
FINISH = 1
HOUR = 0
MINUTE = 1
class Restaurant:
    def __init__(self, lines):
        '''
            table_num: テーブル数（int)
            capacities: 各テーブルに座れる人数（[int])
                - capacities[i]: テーブル i に座れる人数(0 ≤ i ≤ tn - 1)
            range_num: 営業時間帯の数（int)
            ranges: 営業時間帯の集合（[int][int][int])
                - ranges[i][START][HOUR]: i 番目の営業時間帯の開始時刻の時(0 ≤ i ≤ range_num - 1)
                - ranges[i][FINISH][MINUTE]: i 番目の営業時間帯の終了時刻の分(0 ≤ i ≤ range_num - 1)
        '''
        self.table_num = int(lines[0])
        self.capacities = [ int(c) for c in lines[1].split() ]
        rs_str = lines[2].split()
        self.range_num = int(rs_str[1])
        self.ranges = []
        for r_str in rs_str[2:]:
            sf_str = r_str.split('-')
            s_time = [ int(str) for str in sf_str[0].split(':') ]
            f_time = [ int(str) for str in sf_str[1].split(':') ]
            self.ranges.append([ s_time, f_time ])


class Query:
    def __init__(self, strs):
        '''
            day: クエリが送られた日付(int)
            time: クエリが送られた時刻([int])
                - time[HOUR]: クエリが送られた時刻の時
                - time[MINUTE]: クエリが送られた時刻の分
            previous: 1つ前のクエリ
        '''
        self.day = int(strs[0])
        self.time = [ int(s) for s in strs[1].split(':') ]
        self.previous = None
        self.successor = None


class TicketQuery(Query):
    def __init__(self, strs):
        '''
            resevation_index: 予約番号(string)
            resevation_day: 予約日付(int)
            resevation_time: 予約時間帯(int)
            number: 予約人数(int)
            table_index: テーブル番号(int)
        '''
        super().__init__(strs)
        self.resevation_index = strs[3]
        self.resevation_day = int(str[4])
        self.resevation_time = int(str[5])
        self.number = int(str[6])
        self.table_index = int(str[7])
    def process():
        str_hour = '0' + self.time[HOUR] if self.time[HOUR] < 10 else str(self.time[HOUR])
        str_minute = '0' + self.time[MINUTE] if self.time[MINUTE] < 10 else str(self.time[MINUTE])
        print(self.day + ' ' + str_hour + ':' + str_minute + ' ' + self.resevation_index)

class TimeQuery(Query):
    def __init__(self, strs):
        '''
            index: どの営業時間帯の時間クエリであるか(int)
        '''
        super().__init__(strs)
        self.index = int(strs[3])
    def process(k):
        if index <= k:
            queries = []
            current = self
            while current.previous != None:
                q = current.previous
                queries.append([ q.table_index, q ])
            queries.sort()
            for q in queries:
                print(str(self.day) + ' ' + str(self.time[HOUR]) + ':' + str(self.time[MINUTE]) + ' table ' + q.table_index + ' = ' + q.resevation_index)
        if index >= 2:
            self.previous = None

def main(lines):
    # このコードは標準入力と標準出力を用いたサンプルコードです。
    # このコードは好きなように編集・削除してもらって構いません。
    # ---
    # This is a sample code to use stdin and stdout.
    # Edit and remove this code as you like.
    restaurant = Restaurant(lines)
    queries_head = None
    current = None
    strs = lines[3].split()
    if strs[2] == 'time':
        queries_head = TimeQuery(strs)
    else:
        queries_head = TicketQuery(strs)
    queries_head.previous = None
    current = queries_head
    for line in lines[4:]:
        strs = line.split()
        q = None
        if strs[2] == 'time':
            q = TimeQuery(strs)
        else:
            q = TicketQuery(strs)
        current.successor = q
        q.previous = current
        current = q
    current = queries.head
    while current.successor != None:
        current.process()

if __name__ == '__main__':
    lines = []
    for l in sys.stdin:
        lines.append(l.rstrip('\r\n'))
    main(lines)
