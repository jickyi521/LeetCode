

def mergeList(intervals):
    intervals.sort(key=lambda x:x.start)
    merged = []
    for interval in interval:
        if not merged or merged[-1].end < interval.start:
            merged.append(interval)
        else:
            merged[-1].end = max(merged[-1].end, interval.end)
    return merged

print(mergeList([[1,4],[4,5]]))